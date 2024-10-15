#pragma once
#include<iostream>
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include"worker.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;


class WorkerManager  //管理类
{
public:
	
	WorkerManager();


	void Show_Menu();

	void exitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存文件
	void save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计文件中人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//判断职工是否存在
	int IsExist(int id);

	bool IsExist2(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	bool CompareById(const Worker* a, const Worker* b);

	void QuickSort1(Worker** worker, int left, int right);
	void QuickSort2(Worker** worker, int left, int right);

	void swap(Worker*& a, Worker*& b);

	//清空文件
	void Clean_File();


	~WorkerManager();
};


