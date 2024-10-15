#include<iostream>
using namespace std;


//ʵ��ͨ�� �������������ĺ���
//�Ӵ�С
//ѡ������
//����char���飬int����

//��������ģ��
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
        int max=i; //�϶����ֵ���±�
        for(int j=i+1;j<len;j++)
        {
            //�϶������ֵ�ȱ�������ֵС��˵��j�±�������������ֵ
            if(arr[max]<arr[j])
            {
                max=j;
            }
        }
        if(max!=i)
        {
            //����Ԫ��
            mySwap(arr[max],arr[i]);
        }
    }
}

//��ӡ����ģ��
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
    //����char����
    char charArr[]="badcfe";
    int num=sizeof(charArr)/sizeof(char)-1;
    mySort(charArr,num);
    printArr(charArr,num);

}

void test02()
{
    //��������
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