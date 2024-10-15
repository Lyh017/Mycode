#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<string>
#include<ctime>
#define SCHEME 0
#define ART 1
#define RD 2
//公司招聘了10个员工（ABCDEFGHIJ），10名员工进入公司后，需要指派员工在哪个部门工作
//员工信息：姓名  工资组成；部门分为：策划，美术，研发
//随机给10名员工分配部门和工资
//通过multimap进行信息的插入 key(部门编号) value(员工)
//分部门显示员工信息

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
        worker.m_Name="员工";
        worker.m_Name+=nameSeed[i];
        worker.m_Salary=rand()%10000+10000;  //10000~19999

        v.push_back(worker);
    }
}

void setGroup(vector<Worker>&v,multimap<int,Worker>&m)
{
    for(auto i : v)
    {
        //产生随即部门编号
        int deptID=rand()%3;  //0,1,2
        //将员工插入到分组中
        m.insert(make_pair(deptID,i));
    }
}

void showWorkerByGroup(multimap<int,Worker>& m)
{
    cout<<"策划部门:"<<endl;
    auto pos1=m.find(SCHEME);
    int count1=m.count(SCHEME);
    int index1=0;
    for(;pos1!=m.end()&& index1<count1;pos1++,index1++)
    {
        cout<<"姓名:"<<pos1->second.m_Name<<" 工资:"<<pos1->second.m_Salary<<endl;
    }
    cout<<"-----------------------------"<<endl;

    cout<<"美术部门:"<<endl;
    auto pos2=m.find(ART);
    int count2=m.count(ART);
    int index2=0;
    for(;pos2!=m.end()&& index2<count2;pos2++,index2++)
    {
        cout<<"姓名:"<<pos2->second.m_Name<<" 工资:"<<pos2->second.m_Salary<<endl;
    }
    cout<<"-----------------------------"<<endl;

    cout<<"研发部门:"<<endl;
    auto pos3=m.find(RD);
    int count3=m.count(RD);
    int index3=0;
    for(;pos3!=m.end()&& index3<count3;pos3++,index3++)
    {
        cout<<"姓名:"<<pos3->second.m_Name<<" 工资:"<<pos3->second.m_Salary<<endl;
    }
    cout<<"-----------------------------"<<endl;

}

int main()
{
    srand((unsigned int)time(NULL));
    //1.创建员工
    vector<Worker>v;
    createWorker(v);
    // for(auto i : v)
    // {
    //     cout<<"姓名:"<<i.m_Name<<" 工资:"<<i.m_Salary<<endl;
    // }

    //2.员工分组
    multimap<int,Worker> m;
    setGroup(v,m);

    //3.分组显示
    showWorkerByGroup(m);


}