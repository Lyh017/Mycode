#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
//�º�������������bool�������ͣ���Ϊν��
//һԪν��

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val>5;
    }
};

void test01()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    
    //������������û�д���5������
    //GreaterFive��������������
    //GreaterFive gf;
    vector<int>::iterator it=find_if(v.begin(),v.end(),GreaterFive());   //����һ��������������ҵ�����Ԫ��λ�õĵ��������Ҳ������ؽ���������
    if(it==v.end())
    {
        cout<<"δ�ҵ�"<<endl;
    }
    else{
        cout<<"�ҵ��˴���5������Ϊ:"<<*it<<endl;
    }
}

int main()
{
    test01();
    return 0;
}