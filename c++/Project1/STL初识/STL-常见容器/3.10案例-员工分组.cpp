#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<string>
#include<ctime>
#define SCHEME 0
#define ART 1
#define RD 2
//��˾��Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾����Ҫָ��Ա�����ĸ����Ź���
//Ա����Ϣ������  ������ɣ����ŷ�Ϊ���߻����������з�
//�����10��Ա�����䲿�ź͹���
//ͨ��multimap������Ϣ�Ĳ��� key(���ű��) value(Ա��)
//�ֲ�����ʾԱ����Ϣ

class Worker
{
public:
    string m_Name;
    int m_Salary;
};

void createWorker(vector<Worker>& v)
{
    string nameSeed="ABCDEFGHIJ";
    for(int i=0;i<10;i++)
    {
        Worker worker;
        worker.m_Name="Ա��";
        worker.m_Name+=nameSeed[i];
        worker.m_Salary=rand()%10000+10000;  //10000~19999

        v.push_back(worker);
    }
}

void setGroup(vector<Worker>&v,multimap<int,Worker>&m)
{
    for(auto i : v)
    {
        //�����漴���ű��
        int deptID=rand()%3;  //0,1,2
        //��Ա�����뵽������
        m.insert(make_pair(deptID,i));
    }
}

void showWorkerByGroup(multimap<int,Worker>& m)
{
    cout<<"�߻�����:"<<endl;
    auto pos1=m.find(SCHEME);
    int count1=m.count(SCHEME);
    int index1=0;
    for(;pos1!=m.end()&& index1<count1;pos1++,index1++)
    {
        cout<<"����:"<<pos1->second.m_Name<<" ����:"<<pos1->second.m_Salary<<endl;
    }
    cout<<"-----------------------------"<<endl;

    cout<<"��������:"<<endl;
    auto pos2=m.find(ART);
    int count2=m.count(ART);
    int index2=0;
    for(;pos2!=m.end()&& index2<count2;pos2++,index2++)
    {
        cout<<"����:"<<pos2->second.m_Name<<" ����:"<<pos2->second.m_Salary<<endl;
    }
    cout<<"-----------------------------"<<endl;

    cout<<"�з�����:"<<endl;
    auto pos3=m.find(RD);
    int count3=m.count(RD);
    int index3=0;
    for(;pos3!=m.end()&& index3<count3;pos3++,index3++)
    {
        cout<<"����:"<<pos3->second.m_Name<<" ����:"<<pos3->second.m_Salary<<endl;
    }
    cout<<"-----------------------------"<<endl;

}

int main()
{
    srand((unsigned int)time(NULL));
    //1.����Ա��
    vector<Worker>v;
    createWorker(v);
    // for(auto i : v)
    // {
    //     cout<<"����:"<<i.m_Name<<" ����:"<<i.m_Salary<<endl;
    // }

    //2.Ա������
    multimap<int,Worker> m;
    setGroup(v,m);

    //3.������ʾ
    showWorkerByGroup(m);


}