#include<iostream>
using namespace std;
#include<vector>

//vector Ԥ���ռ� ����vector�ڶ�̬��չʱ����չ����
//reserve(int len); ����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ���

void test01()
{
    vector<int>v1;
    int num=0;  //ͳ�ƿ��ٿռ�Ĵ���
    int* p=NULL;

    //����reserveԤ���ռ�
    v1.reserve(100000);

    for(int i=0;i<100000;i++)
    {
        v1.push_back(i);
        
        if(p!=&v1[0])
        {
            p=&v1[0];
            num++;
        }
    }
    cout<<num<<endl;
}

int main()
{
    test01();
    return 0;
}