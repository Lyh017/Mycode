#include<iostream>
using namespace std;

class AbstractDrinking
{
public:
    //煮水
    virtual void Boil()=0;
    //冲泡
    virtual void Brew()=0;
    //倒入杯中
    virtual void PourInCup()=0;
    //加入辅料
    virtual void AddSome()=0;

    //制作饮品
    void MakeDrink()
    {
        Boil();
    
        Brew();
   
        PourInCup();
    
        AddSome();
    }

    virtual ~AbstractDrinking()
    {
        
    }
};


//制作咖啡
class Coffee : public AbstractDrinking
{
public:
    //煮水
    virtual void Boil()
    {
        cout<<"煮矿泉水"<<endl;
    }
    //冲泡
    virtual void Brew()
    {
        cout<<"冲泡咖啡"<<endl;
    }
    //倒入杯中
    virtual void PourInCup()
    {
        cout<<"倒入杯中"<<endl;
    }
    //加入辅料
    virtual void AddSome()
    {
        cout<<"加入糖和牛奶"<<endl;
    }


};


//制作咖啡
class Tea : public AbstractDrinking
{
public:
     //煮水
    virtual void Boil()
    {
        cout<<"煮白开水"<<endl;
    }
    //冲泡
    virtual void Brew()
    {
        cout<<"冲泡茶叶"<<endl;
    }
    //倒入杯中
    virtual void PourInCup()
    {
        cout<<"倒入茶杯"<<endl;
    }
    //加入辅料
    virtual void AddSome()
    {
        cout<<"加入枸杞"<<endl;
    }

};

void doWork(AbstractDrinking* drink)
{
    drink->MakeDrink();
    delete drink;
}


void test01()
{
    //制作咖啡
    doWork(new Coffee);
    
    //制作茶
    doWork(new Tea);
}


int main()
{

    test01();
    return 0;
}