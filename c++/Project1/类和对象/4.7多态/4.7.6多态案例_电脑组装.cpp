#include<iostream>
#include<string>
using namespace std;

//CPU������
class CPU
{
public:
    virtual void calculate()=0;
};

//GPU������
class GPU
{
public:
    virtual void display()=0;
};

//Memory������
class Memory
{
public:
    virtual void storage()=0;

};


//�����������
//Intel
class IntelCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout<<"Intel��CPU��ʼ����"<<endl;
    }
};

class NVIDIAGPU : public GPU
{
public:
    virtual void display()
    {
        cout<<"NVIDIA��GPU��ʼ����"<<endl;
    }
};

class IntelMemory : public Memory
{
public:
    virtual void storage()
    {
        cout<<"Inter��Memory���ڶ�ȡ����"<<endl;
    }
};

class AMDGPU : public GPU
{
public:
    virtual void display()
    {
        cout<<"AMD��GPU��ʼ����"<<endl;
    }
};

class AMDCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout<<"AMD R7���ڼ���"<<endl;
    }
};

class LenovoMemory : public Memory
{
public:
    virtual void storage()
    {
        cout<<"Lenovo��Memory���ڶ�ȡ����"<<endl;
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

    //�ṩ���������ͷŵ������
    ~Computer()
    {
        cout<<"Computer����"<<endl;
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