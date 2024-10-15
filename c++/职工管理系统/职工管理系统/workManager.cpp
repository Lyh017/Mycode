#define _CRT_SECURE_NO_WARNINGS
#include "workManager.h"
using namespace std;

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在且保存了职工记录
	int num = this->get_EmpNum();
	//cout << "职工的人数为: " <<num<< endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [num];  //开辟空间
	this->init_Emp();			//将文件中的数据存到数组

	

}

//显示职工
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用接口
			this->m_EmpArray[i]->showInfo();
		}

	}
	system("pause");
	system("cls");
}


WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void WorkerManager::Show_Menu()
{
	cout << "**********************************" << endl;
	cout << "****** 欢迎使用职工管理系统 ******" << endl;
	cout << "********* 0.退出管理系统 *********" << endl;
	cout << "********* 1.增加职工信息 *********" << endl;
	cout << "********* 2.显示职工信息 *********" << endl;
	cout << "********* 3.删除离职职工 *********" << endl;
	cout << "********* 4.修改职工信息 *********" << endl;
	cout << "********* 5.查找职工信息 *********" << endl;
	cout << "********* 6.按照编号排序 *********" << endl;
	cout << "********* 7.清空所有文档 *********" << endl;
	cout << endl;


}


//统计人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int Id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> Id && ifs >> name && ifs >> dId)  //ifstream 对象 ifs 会根据空格、制表符或换行符来分隔不同的数据
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}

//初始化员工
void WorkerManager :: init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}



//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);  //输出方式打开文件 ——写文件
	for (int i = 0; i < this->m_EmpNum; i++)
	{


		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;

	}
	ofs.close();
}

//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量: " << endl;

	//保存用户的输入
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;   //原来记录人数+新增人数

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来空间下数据拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新的数据
		for (int i = 0; i < addNum; i++)
		{
			int id = 0;
			string name;
			int dSelect = 0;  //部门选择

			do
			{
				cout << "请输入第" << i + 1 << "个新职工的编号: " << endl;
				cin >> id;
				
			} while (this->IsExist2(id));
			
			cout << "请输入第" << i + 1 << "个新职工的姓名: " << endl;
			cin >> name;
			cout << "请选择该职工岗位: " << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建职工指针，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//更改新空间指向
		this->m_EmpArray = newSpace;
		//更新职工人数
		this->m_EmpNum = newSize;
		//更新职工不为空
		this->m_FileIsEmpty = false;

		//成功添加后保存在文件中
		this->save();

		cout << "成功添加" << addNum << "名新职工" << endl;

	}
	else
	{
		cout << "输入数据有误" << endl;
	}

	//按任意键后清屏回到上级目录
	system("pause");
	system("cls");

}


//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		cout << "请输入要删除的员工编号: " << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1) //职工存在并且要删除index位置
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			this->m_EmpNum--;
			this->save();

			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到职工" << endl;
		}
	}

	system("pause");
	system("cls");
	
	
}


//判断职工是否存在，若存在返回职工在数组中的位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

bool WorkerManager::IsExist2(int id)
{
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			cout << "该编号已存在，请重新输入" << endl;
			return true; // 编号已存在，返回true
		}
	}
	return false; // 编号不存在，返回false
}

//修改职工
void WorkerManager :: Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;

	}
	else
	{
		cout << "请输入修改的职工编号: " << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			//查找到编号的职工
			delete this->m_EmpArray[index];

			int newid = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到: " << id << "号职工，请输入新职工号" << endl;
			cin >> newid;
			cout << "请输入姓名: " << endl;
			cin >> newName;
			cout << "请输入岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(newid, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newid, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newid, newName, dSelect);
				break;
			default:
				break;
			}

			this->m_EmpArray[index] = worker;
			cout << "修改成功！" << this->m_EmpArray[index]->m_DeptId << endl;
			this->save();

		}
		else
		{
			cout << "修改失败，没有找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}


//查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;

	}
	else
	{
		cout << "请输入查找方式: " << endl;
		cout << "1.按编号查找    " << endl;
		cout << "2.按姓名查找    " << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入要查找的编号" << endl;
			cin >> id;

			int ret = IsExist(id);   //在类的成员函数内部调用另一个成员函数，可以直接使用成员函数的名称，而不需要显式地使用 this-> 来引用
			if (ret != -1)
			{
				//找到
				cout << "查找成功！人员信息如下: " << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}

		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找的姓名: " << endl;
			cin >> name;
			bool flag = false;

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功！人员信息如下: " << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
				
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}

	}
	system("pause");
	system("cls");
}



//排序职工
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");

	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1.按编号升序" << endl;
		cout << "2.按编号降序" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			QuickSort1(this->m_EmpArray, 0, this->m_EmpNum - 1);
			cout << "排序成功!排序后的结果为: " << endl;
			//this->save();
			this->Show_Emp();
		}
		else if (select == 2)
		{
			QuickSort2(this->m_EmpArray, 0, this->m_EmpNum - 1);
			cout << "排序成功!排序后的结果为: " << endl;
			//this->save();
			this->Show_Emp();
		}
		else
		{
			cout << "选择错误" << endl;
		}
	}
}

bool WorkerManager:: CompareById(const Worker* a, const Worker* b)
{
	return a->m_Id < b->m_Id;
}

void WorkerManager::QuickSort1(Worker** worker, int left, int right)
{

	if (left >= right)
	{
		return;
	}

	int begin = left;
	int end = right;
	int keyi = begin;
	while (begin < end)
	{
		while (begin < end && CompareById(this->m_EmpArray[keyi], this->m_EmpArray[end]))
		{
			--end;
		}


		while (begin < end && CompareById(this->m_EmpArray[begin], this->m_EmpArray[keyi]))
		{
			++begin;
		}
		swap(this->m_EmpArray[begin], this->m_EmpArray[end]);
		
	}
	swap(this->m_EmpArray[begin], this->m_EmpArray[keyi]);
	


	QuickSort1(this->m_EmpArray, left, begin - 1); 
	QuickSort1(this->m_EmpArray, begin + 1, right);

}

void WorkerManager::QuickSort2(Worker** worker, int left, int right)
{

	if (left >= right)
	{
		return;
	}

	int begin = left;
	int end = right;
	int keyi = begin;
	while (begin < end)
	{
		while (begin < end && CompareById(this->m_EmpArray[end], this->m_EmpArray[keyi]))
		{
			--end;
		}


		while (begin < end && CompareById(this->m_EmpArray[keyi], this->m_EmpArray[begin]))
		{
			++begin;
		}
		swap(this->m_EmpArray[begin], this->m_EmpArray[end]);

	}
	swap(this->m_EmpArray[begin], this->m_EmpArray[keyi]);



	QuickSort2(this->m_EmpArray, left, begin - 1);
	QuickSort2(this->m_EmpArray, begin + 1, right);

}

void WorkerManager::swap(Worker*& a, Worker*& b)
{
	Worker* temp = a;
	a = b;
	b = temp;
}


void WorkerManager::Clean_File()
{
	cout << "确认清空?" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc); //删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}

		cout << "清空成功!" << endl;


	}

	system("pause");
	system("cls");
}

