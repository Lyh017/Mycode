#include<iostream>
using namespace std;

class Person {
public:
    Person(int age) : age(age) {}
    Person(const Person& other) : age(other.age) {
        cout << "�������캯�����ã���ַ��" << this << endl;
    }
    int age;
};

Person createPerson() {
    Person p(30);
    cout << "p�ĵ�ַ��" << &p << endl;
    return p;  // ���ض��󸱱�
}

int main() {
    Person p1 = createPerson();
    cout << "p1�ĵ�ַ��" << &p1 << endl;
    return 0;
}
