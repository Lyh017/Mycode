#include<iostream>
using namespace std;
#include<set>

//set���Һ�ͳ��
void test01()
{
    set<int>s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);

    set<int>::iterator pos=s1.find(4);  //����key�Ƿ���ڣ����ظü���Ԫ�صĵ��������������ڷ���set.end();
    if(pos!=s1.end())
    {
        cout<<"�ҵ���Ԫ��:"<<*pos<<endl;
    }
    else{
        cout<<"δ�ҵ�Ԫ��"<<endl;
    }
}
//ͳ��
void test02()
{
    set<int>s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(50);

    int num=s1.count(40); //ͳ��40�ĸ���
    cout<<"num="<<num<<endl;
    //����set���ԣ�ͳ�ƽ��Ҫô��0��Ҫô��1
}

int main()
{
    //test01();
    test02();
    return 0;
}