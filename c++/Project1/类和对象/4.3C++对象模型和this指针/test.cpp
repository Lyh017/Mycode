#include<iostream>
using namespace std;

class Person {
public:
    Person(int age) : age(age) {}
    Person(const Person& other) : age(other.age) {
        cout << "拷贝构造函数调用，地址：" << this << endl;
    }
    int age;
};

Person createPerson() {
    Person p(30);
    cout << "p的地址：" << &p << endl;
    return p;  // 返回对象副本
}

int main() {
    Person p1 = createPerson();
    cout << "p1的地址：" << &p1 << endl;
    return 0;
}
