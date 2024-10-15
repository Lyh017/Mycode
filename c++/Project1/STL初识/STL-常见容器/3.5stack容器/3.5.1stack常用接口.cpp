#include<iostream>
#include<stack>
using namespace std;

//stack容器
void test01()
{
    stack<int>s;

    //入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    //只要栈不为空就查看栈顶，并执行出栈操作
    while(!s.empty())
    {
        //查看栈顶元素
        cout<<"栈顶元素为:"<<s.top()<<endl;

        //出栈
        s.pop();
    }
    cout<<"栈的大小:"<<s.size()<<endl;

}

int main()
{
    test01();
    return 0;
}