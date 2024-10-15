#define _CRT_SECURE_NO_WARNINGS
#include "workManager.h"
using namespace std;

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//�ļ�������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ������ұ�����ְ����¼
	int num = this->get_EmpNum();
	//cout << "ְ��������Ϊ: " <<num<< endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [num];  //���ٿռ�
	this->init_Emp();			//���ļ��е����ݴ浽����

	

}

//��ʾְ��
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ýӿ�
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
	cout << "****** ��ӭʹ��ְ������ϵͳ ******" << endl;
	cout << "********* 0.�˳�����ϵͳ *********" << endl;
	cout << "********* 1.����ְ����Ϣ *********" << endl;
	cout << "********* 2.��ʾְ����Ϣ *********" << endl;
	cout << "********* 3.ɾ����ְְ�� *********" << endl;
	cout << "********* 4.�޸�ְ����Ϣ *********" << endl;
	cout << "********* 5.����ְ����Ϣ *********" << endl;
	cout << "********* 6.���ձ������ *********" << endl;
	cout << "********* 7.��������ĵ� *********" << endl;
	cout << endl;


}


//ͳ������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int Id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> Id && ifs >> name && ifs >> dId)  //ifstream ���� ifs ����ݿո��Ʊ�����з����ָ���ͬ������
	{
		//��¼����
		num++;
	}
	ifs.close();

	return num;
}

//��ʼ��Ա��
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
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}



//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);  //�����ʽ���ļ� ����д�ļ�
	for (int i = 0; i < this->m_EmpNum; i++)
	{


		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;

	}
	ofs.close();
}

//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ������: " << endl;

	//�����û�������
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;   //ԭ����¼����+��������

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ������ݿ������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//����µ�����
		for (int i = 0; i < addNum; i++)
		{
			int id = 0;
			string name;
			int dSelect = 0;  //����ѡ��

			do
			{
				cout << "�������" << i + 1 << "����ְ���ı��: " << endl;
				cin >> id;
				
			} while (this->IsExist2(id));
			
			cout << "�������" << i + 1 << "����ְ��������: " << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ: " << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//������ְ��ָ�룬���浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;
		//����ְ������
		this->m_EmpNum = newSize;
		//����ְ����Ϊ��
		this->m_FileIsEmpty = false;

		//�ɹ���Ӻ󱣴����ļ���
		this->save();

		cout << "�ɹ����" << addNum << "����ְ��" << endl;

	}
	else
	{
		cout << "������������" << endl;
	}

	//��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");

}


//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫɾ����Ա�����: " << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1) //ְ�����ڲ���Ҫɾ��indexλ��
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			this->m_EmpNum--;
			this->save();

			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ�ְ��" << endl;
		}
	}

	system("pause");
	system("cls");
	
	
}


//�ж�ְ���Ƿ���ڣ������ڷ���ְ���������е�λ�ã������ڷ���-1
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
			cout << "�ñ���Ѵ��ڣ�����������" << endl;
			return true; // ����Ѵ��ڣ�����true
		}
	}
	return false; // ��Ų����ڣ�����false
}

//�޸�ְ��
void WorkerManager :: Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;

	}
	else
	{
		cout << "�������޸ĵ�ְ�����: " << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			//���ҵ���ŵ�ְ��
			delete this->m_EmpArray[index];

			int newid = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽: " << id << "��ְ������������ְ����" << endl;
			cin >> newid;
			cout << "����������: " << endl;
			cin >> newName;
			cout << "�������λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			cout << "�޸ĳɹ���" << this->m_EmpArray[index]->m_DeptId << endl;
			this->save();

		}
		else
		{
			cout << "�޸�ʧ�ܣ�û���ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}


//����ְ��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;

	}
	else
	{
		cout << "��������ҷ�ʽ: " << endl;
		cout << "1.����Ų���    " << endl;
		cout << "2.����������    " << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "������Ҫ���ҵı��" << endl;
			cin >> id;

			int ret = IsExist(id);   //����ĳ�Ա�����ڲ�������һ����Ա����������ֱ��ʹ�ó�Ա���������ƣ�������Ҫ��ʽ��ʹ�� this-> ������
			if (ret != -1)
			{
				//�ҵ�
				cout << "���ҳɹ�����Ա��Ϣ����: " << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}

		}
		else if (select == 2)
		{
			string name;
			cout << "��������ҵ�����: " << endl;
			cin >> name;
			bool flag = false;

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�����Ա��Ϣ����: " << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
				
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "������������������" << endl;
		}

	}
	system("pause");
	system("cls");
}



//����ְ��
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");

	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1.���������" << endl;
		cout << "2.����Ž���" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			QuickSort1(this->m_EmpArray, 0, this->m_EmpNum - 1);
			cout << "����ɹ�!�����Ľ��Ϊ: " << endl;
			//this->save();
			this->Show_Emp();
		}
		else if (select == 2)
		{
			QuickSort2(this->m_EmpArray, 0, this->m_EmpNum - 1);
			cout << "����ɹ�!�����Ľ��Ϊ: " << endl;
			//this->save();
			this->Show_Emp();
		}
		else
		{
			cout << "ѡ�����" << endl;
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
	cout << "ȷ�����?" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc); //ɾ���ļ������´���
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

		cout << "��ճɹ�!" << endl;


	}

	system("pause");
	system("cls");
}

