#pragma once
#include "worker.h"
using namespace std;


class Employee :public Worker
{
public:
	Employee(int id, string name, int dId);

	//显示个人信息
	virtual void showInfo();
	

	//获取岗位名称
	virtual string getDeptName();
	
};
