//自己的通用数组类
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
        //cout<<"有参构造"<<endl;
        this->m_Capacity=capacity;
        this->m_Size=0;
        this->pAddress=new T[this->m_Capacity];
    }

    //拷贝构造
    MyArray(const MyArray& arr)
    {
        //cout<<"拷贝构造"<<endl;
        this->m_Capacity=arr.m_Capacity;
        this->m_Size=arr.m_Size;
        //深拷贝
        this->pAddress = new T[arr.m_Capacity];

        //将arr中的数据拷进来
        for(int i=0;i<this->m_Size;i++)
        {
            this->pAddress[i]=arr.pAddress[i];
        }
    }

    //operator=防止浅拷贝
    MyArray& operator=(const MyArray& arr)
    {
        //cout<<"operator=调用"<<endl;
        //先判断原来堆区是否有数据，如果有先释放
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

    //尾插法
    void PushBack(const T& val)
    {
        //判断容量是否等于大小
        if(this->m_Capacity==this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size]=val;
        this->m_Size++;
    }

    //尾删法
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

    //通过下标访问元素,重载[]
    T& operator[](int index)      //如果还想作为=的左值，要返回引用
    {
        return this->pAddress[index];
    }


    //返回数组容量
    int getCapcity()
    {
        return this->m_Capacity;
    }

    //返回数组大小
    int getSize()
    {
        return this->m_Size;
    }


    ~MyArray()
    {
        if(this->pAddress!=NULL)
        {
            //cout<<"析构调用"<<endl;
            delete[] this->pAddress;
            this->pAddress=NULL;
        }
    }

private:
    T * pAddress;   //指向堆区开辟的真实数组

    int m_Capacity;  //数组容量
    
    int m_Size;     //数组大小
};