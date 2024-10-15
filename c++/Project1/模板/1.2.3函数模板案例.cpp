#include<iostream>
using namespace std;


//实现通用 对数组进行排序的函数
//从大到小
//选择排序
//测试char数组，int数组

//交换函数模板
template<typename T>
void mySwap(T& a,T& b)
{
    
    T temp = a;
    a = b;
    b = temp;
}


template<typename T>
void mySort(T arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        int max=i; //认定最大值的下标
        for(int j=i+1;j<len;j++)
        {
            //认定的最大值比遍历的数值小，说明j下标才是真正的最大值
            if(arr[max]<arr[j])
            {
                max=j;
            }
        }
        if(max!=i)
        {
            //交换元素
            mySwap(arr[max],arr[i]);
        }
    }
}

//打印数组模板
template<typename T>
void printArr(T arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void test01()
{
    //测试char数组
    char charArr[]="badcfe";
    int num=sizeof(charArr)/sizeof(char)-1;
    mySort(charArr,num);
    printArr(charArr,num);

}

void test02()
{
    //测试整型
    int IntArr[]={4,3,1,6,8,9,1,10,4};
    int num=sizeof(IntArr)/sizeof(IntArr[0]);
    mySort(IntArr,num);
    printArr(IntArr,num);
}


int main()
{
    test01();
    test02();
    return 0;
}