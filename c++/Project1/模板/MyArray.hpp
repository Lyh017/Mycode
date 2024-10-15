//�Լ���ͨ��������
#pragma once
#include<iostream>
using namespace std;
#include <string>

template<class T>
class MyArray
{
public:
    MyArray(int capacity)
    {
        //cout<<"�вι���"<<endl;
        this->m_Capacity=capacity;
        this->m_Size=0;
        this->pAddress=new T[this->m_Capacity];
    }

    //��������
    MyArray(const MyArray& arr)
    {
        //cout<<"��������"<<endl;
        this->m_Capacity=arr.m_Capacity;
        this->m_Size=arr.m_Size;
        //���
        this->pAddress = new T[arr.m_Capacity];

        //��arr�е����ݿ�����
        for(int i=0;i<this->m_Size;i++)
        {
            this->pAddress[i]=arr.pAddress[i];
        }
    }

    //operator=��ֹǳ����
    MyArray& operator=(const MyArray& arr)
    {
        //cout<<"operator=����"<<endl;
        //���ж�ԭ�������Ƿ������ݣ���������ͷ�
        if(this->pAddress!=NULL)
        {
            delete[] this->pAddress;
            this->pAddress=NULL;
            this->m_Capacity=0;
            this->m_Size=0;
        }
        this->pAddress=new T[arr.m_Capacity];
        this->m_Size=arr.m_Size;
        this->m_Capacity=arr.m_Capacity;
        for(int i=0;i<this->m_Size;i++)
        {
            this->pAddress[i]=arr.pAddress[i];
        }
        return *this;
    }

    //β�巨
    void PushBack(const T& val)
    {
        //�ж������Ƿ���ڴ�С
        if(this->m_Capacity==this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size]=val;
        this->m_Size++;
    }

    //βɾ��
    void PopBack()
    {
        if(this->m_Size==0)
        {
            return;
        }
        else
        {
            this->m_Size--;
        }
    }

    //ͨ���±����Ԫ��,����[]
    T& operator[](int index)      //���������Ϊ=����ֵ��Ҫ��������
    {
        return this->pAddress[index];
    }


    //������������
    int getCapcity()
    {
        return this->m_Capacity;
    }

    //���������С
    int getSize()
    {
        return this->m_Size;
    }


    ~MyArray()
    {
        if(this->pAddress!=NULL)
        {
            //cout<<"��������"<<endl;
            delete[] this->pAddress;
            this->pAddress=NULL;
        }
    }

private:
    T * pAddress;   //ָ��������ٵ���ʵ����

    int m_Capacity;  //��������
    
    int m_Size;     //�����С
};