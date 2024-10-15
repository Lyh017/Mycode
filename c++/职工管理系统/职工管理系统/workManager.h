#pragma once
#include<iostream>
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include"worker.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;


class WorkerManager  //������
{
public:
	
	WorkerManager();


	void Show_Menu();

	void exitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ����
	int IsExist(int id);

	bool IsExist2(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����ְ��
	void Sort_Emp();

	bool CompareById(const Worker* a, const Worker* b);

	void QuickSort1(Worker** worker, int left, int right);
	void QuickSort2(Worker** worker, int left, int right);

	void swap(Worker*& a, Worker*& b);

	//����ļ�
	void Clean_File();


	~WorkerManager();
};


