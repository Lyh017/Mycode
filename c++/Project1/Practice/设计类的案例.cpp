#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Cube
{
public:
	//行为


	//设置获取长宽高
	void set_L(int L)
	{
		m_L = L;
	}
	void set_W(int W)
	{
		m_W = W;
	}
	void set_H(int H)
	{
		m_H = H;
	}
	int getL()
	{
		return m_L;
	}
	int getW()
	{
		return m_W;
	}
	int getH()
	{
		return m_H;
	}

	//获取立方体面积
	int CubeArea(int L, int W, int H)
	{
		return L * H * 2 + W * H * 2 + L * W * 2;
	}
	//获取立方体体积
	int Vcube(int L,int W,int H)
	{
		return L * W * H;
	}


private:
	//属性
	int m_L;
	int m_W;
	int m_H;
};


//设计圆类和点类

class Point
{
public:
	void setX(int x)
	{
		m_X = x;
	}
	void setY(int y)
	{
		m_Y = y;
	}
	int getX()
	{
		return m_X;
	}
	int getY()
	{
		return m_Y;
	}
private:
	int m_X;
	int m_Y;
};

class Circle
{
public:
	//设置半径，获取半径
	void setR(int r)
	{
		m_R = r;
	}
	int getR()
	{
		return m_R;
	}
	//设置圆心，获取圆心
	void setCenter(int x, int y)
	{
		m_Center.setX(x);
		m_Center.setY(y);
	}
	Point getCenter()
	{
		return m_Center;
	}
	

private:
	int m_R; //半径
	Point m_Center; //圆心

};
//判断点和圆的关系
void isInCircle(Circle& c, Point& p)
{
	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

	int rDistance = c.getR() * c.getR();

	if (distance == rDistance)
	{
		cout << "点在圆上" << endl;
		
	}
	else if (distance > rDistance)
	{
		cout << "点在圆外" << endl;

	}
	else
	{
		cout << "点在圆内" << endl;

	}
}

int main()
{
	/*Cube cube1;
	cube1.set_H(10);
	cube1.set_L(5);
	cube1.set_W(4);
	cout << "立方体的面积是：" << cube1.CubeArea(cube1.getL(), cube1.getW(), cube1.getH()) << endl;
	cout << "立方体的体积是：" << cube1.Vcube(cube1.getL(), cube1.getW(), cube1.getH()) << endl;*/
	Circle c;
	Point p;
	p.setX(10);
	p.setY(10);
	c.setR(10);
	c.setCenter(10, 0);
	cout << "圆的半径：" << c.getR() << endl;
	cout << "圆心："<< c.getCenter().getX()<<","<<c.getCenter().getY() << endl;
	isInCircle(c, p);
	return 0;
}