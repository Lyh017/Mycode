#define _CRT_SECURE_NO_WARNINGS
#include"workManager.h"
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
using namespace std;

int main()
{
	/*Worker* worker1 = NULL;
	worker1 = new Employee(1, "����", 1);
	worker1->showInfo();
	delete worker1;

	Worker* worker2 = NULL;
	worker2 = new Manager(2, "����", 2);
	worker2->showInfo();
	delete worker2;*/

	WorkerManager wm;
	int choice = 0;

	while (true)
	{
		//չʾ�˵�
		wm.Show_Menu();
		cout << "���������ѡ��: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitSystem();
			break; //�˳�
		case 1:		
			wm.Add_Emp();
			break;
		case 2:
			wm.Show_Emp();
			break;
		case 3:
			wm.Del_Emp();
			break;
		case 4:
			wm.Mod_Emp();
			break;
		case 5:
			wm.Find_Emp();
			break;
		case 6:
			wm.Sort_Emp();
			break;
		case 7:
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}

	return 0;
}