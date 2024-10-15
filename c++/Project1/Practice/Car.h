#pragma once
#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
	int registration;
	string color;
	Car();

	int getRegistration()
	{
		return registration;
	}
	string getColor()
	{
		return color;
	}
	void setRegistration(int pReg)
	{
		registration = pReg;
	}
	void setColor(string pcolor)
	{
		color = pcolor;
	}
};