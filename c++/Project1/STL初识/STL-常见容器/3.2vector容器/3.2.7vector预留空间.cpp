#include<iostream>
using namespace std;
#include<vector>

//vector 预留空间 减少vector在动态扩展时的扩展次数
//reserve(int len); 容器预留len个元素长度，预留位置不初始化，元素不可访问

void test01()
{
    vector<int>v1;
    int num=0;  //统计开辟空间的次数
    int* p=NULL;

    //利用reserve预留空间
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