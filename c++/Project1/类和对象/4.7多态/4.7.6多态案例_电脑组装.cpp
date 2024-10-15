#include<iostream>
#include<string>
using namespace std;

//CPU抽象类
class CPU
{
public:
    virtual void calculate()=0;
};

//GPU抽象类
class GPU
{
public:
    virtual void display()=0;
};

//Memory抽象类
class Memory
{
public:
    virtual void storage()=0;

};


//具体零件厂商
//Intel
class IntelCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout<<"Intel的CPU开始计算"<<endl;
    }
};

class NVIDIAGPU : public GPU
{
public:
    virtual void display()
    {
        cout<<"NVIDIA的GPU开始工作"<<endl;
    }
};

class IntelMemory : public Memory
{
public:
    virtual void storage()
    {
        cout<<"Inter的Memory正在读取数据"<<endl;
    }
};

class AMDGPU : public GPU
{
public:
    virtual void display()
    {
        cout<<"AMD的GPU开始工作"<<endl;
    }
};

class AMDCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout<<"AMD R7正在计算"<<endl;
    }
};

class LenovoMemory : public Memory
{
public:
    virtual void storage()
    {
        cout<<"Lenovo的Memory正在读取数据"<<endl;
    }

};

class Computer
{
public:
    Computer(CPU* cpu,GPU*gpu,Memory* mem)
    {   
        m_cpu=cpu;
        m_gpu=gpu;
        m_mem=mem;
    }

    void doWork()
    {
        m_cpu->calculate();
        m_gpu->display();
        m_mem->storage();
    }

    //提供析构函数释放电脑零件
    ~Computer()
    {
        cout<<"Computer析构"<<endl;
        if(m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu=NULL;
        }

        if(m_gpu != NULL)
        {
            delete m_gpu;
            m_gpu=NULL;
        }
        if(m_mem != NULL)
        {
            delete m_mem;
            m_mem=NULL;
        }
    }

private:
    CPU* m_cpu;
    GPU* m_gpu;
    Memory* m_mem;

};


void test01()
{
    Computer *PC1 = new Computer(new IntelCPU,new NVIDIAGPU,new IntelMemory);
    PC1->doWork();
    delete PC1;
     

    Computer *PC2 = new Computer(new AMDCPU,new AMDGPU,new LenovoMemory); 
    PC2->doWork();
    delete PC2;

}


int main()
{
    test01();
    return 0;
}