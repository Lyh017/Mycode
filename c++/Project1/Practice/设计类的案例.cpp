#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Cube
{
public:
	//��Ϊ


	//���û�ȡ�����
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

	//��ȡ���������
	int CubeArea(int L, int W, int H)
	{
		return L * H * 2 + W * H * 2 + L * W * 2;
	}
	//��ȡ���������
	int Vcube(int L,int W,int H)
	{
		return L * W * H;
	}


private:
	//����
	int m_L;
	int m_W;
	int m_H;
};


//���Բ��͵���

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
	//���ð뾶����ȡ�뾶
	void setR(int r)
	{
		m_R = r;
	}
	int getR()
	{
		return m_R;
	}
	//����Բ�ģ���ȡԲ��
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
	int m_R; //�뾶
	Point m_Center; //Բ��

};
//�жϵ��Բ�Ĺ�ϵ
void isInCircle(Circle& c, Point& p)
{
	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

	int rDistance = c.getR() * c.getR();

	if (distance == rDistance)
	{
		cout << "����Բ��" << endl;
		
	}
	else if (distance > rDistance)
	{
		cout << "����Բ��" << endl;

	}
	else
	{
		cout << "����Բ��" << endl;

	}
}

int main()
{
	/*Cube cube1;
	cube1.set_H(10);
	cube1.set_L(5);
	cube1.set_W(4);
	cout << "�����������ǣ�" << cube1.CubeArea(cube1.getL(), cube1.getW(), cube1.getH()) << endl;
	cout << "�����������ǣ�" << cube1.Vcube(cube1.getL(), cube1.getW(), cube1.getH()) << endl;*/
	Circle c;
	Point p;
	p.setX(10);
	p.setY(10);
	c.setR(10);
	c.setCenter(10, 0);
	cout << "Բ�İ뾶��" << c.getR() << endl;
	cout << "Բ�ģ�"<< c.getCenter().getX()<<","<<c.getCenter().getY() << endl;
	isInCircle(c, p);
	return 0;
}