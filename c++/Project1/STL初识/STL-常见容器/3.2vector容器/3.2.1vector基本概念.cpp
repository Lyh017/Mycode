#include<iostream>
using namespace std;
#include<vector>

//vector���ݽṹ������ǳ����ƣ�Ҳ�Ƶ�������
//vector���Զ�̬��չ��������ԭ�ռ�֮�������¿ռ䣬����Ѱ�Ҹ�����ڴ�ռ䣬Ȼ��ԭ���ݿ����¿ռ䣬�ͷ�ԭ�ռ�
//vector�����ĵ�������֧��������ʵĵ�����

//vector���캯��

void printVector(vector<int> &v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01()
{
    vector<int> v1;  //Ĭ�Ϲ��죬�޲ι���
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);

    }
    printVector(v1);

    //ͨ������ķ�ʽ���й���
    vector<int>v2(v1.begin(),v1.end());
    printVector(v2);

    //n��elem��ʽ����
    vector<int>v3(10,1);   //10��1
    printVector(v3);

    //��������
    vector<int>v4(v3);
    printVector(v4);
}

int main()
{
    test01();
    return 0;
}