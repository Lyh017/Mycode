#include "MyArray.hpp"

void printIntArray(MyArray<int>& arr)
{
    for(int i=0;i<arr.getSize();i++)
    {
        cout<<arr[i]<<endl;
    }
}

void test01()
{
    MyArray<int> arr1(5);
    
    for(int i=0;i<5;i++)
    {
        arr1.PushBack(i);
        
    }
    printIntArray(arr1);
    cout<<"arr1������Ϊ��"<<arr1.getCapcity()<<endl;
    
    MyArray<int>arr2(arr1);
    arr2.PopBack();
    printIntArray(arr2);
    cout<<"arr2������Ϊ��"<<arr2.getCapcity()<<endl;
    cout<<"arr2�Ĵ�СΪ��"<<arr2.getSize()<<endl;


}

//�����Զ�����������
class Person
{
public:
    Person(){};
    Person(string name,int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }

    string m_Name;
    int m_Age;

};

void printPersonArray(MyArray<Person>& arr)
{   
    for(int i=0;i<arr.getSize();i++)
    {
        cout<<"������"<<arr[i].m_Name<<" ���䣺"<<arr[i].m_Age<<endl;
    }
}

void test02()
{
    MyArray<Person>arr(10);
    Person p1("Luka",25);
    Person p2("Towns",28);
    Person p3("Eason",40);
    Person p4("Jacky",20);

    arr.PushBack(p1);
    arr.PushBack(p2);
    arr.PushBack(p3);
    arr.PushBack(p4);

    printPersonArray(arr);

    cout<<"arr������Ϊ��"<<arr.getCapcity()<<endl;
    cout<<"arr�Ĵ�СΪ��"<<arr.getSize()<<endl;
}


int main()
{
    //test01();
    test02();
    return 0;
}