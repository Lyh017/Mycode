#include<iostream>
#include<vector>
using namespace std;

// �����ڽӾ���ʵ�ֵ�������ͼ
class GraphAdjMat{
private:
    vector<int> vertices;   //�����б�Ԫ�ش�������ֵ������������������
    vector<vector<int>> adjMat;  //�ڽӾ�������������Ӧ��������

public:
    //���캯��
    GraphAdjMat(const vector<int> &vertices,const vector<vector<int>> &edges)
    {
        //��Ӷ���
        for(int val : vertices)
        {
            addVertex(val);
        }

        //��ӱ�
        for(const vector<int> &edge : edges)
        {
            addEdge(edge[0],edge[1]);
        }
    }

    int size() const{
        return vertices.size();
    }

    template <typename T>
    void printVector(const vector<T>& vec) 
    {
        cout << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i != vec.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    template <typename T>
    void printVectorMatrix(const vector<vector<T>>& matrix) {
        for (const auto& row : matrix) {
            printVector(row);  // ���� printVector ��ӡÿһ��
        }
    }

    void addVertex(int val)
    {
        int n = size();
        // �򶥵��б�������¶����ֵ
        vertices.push_back(val);
        // ���ڽӾ��������һ��
        adjMat.emplace_back(vector<int>(n, 0));
        // ���ڽӾ��������һ��
        for (vector<int> &row : adjMat) {
            row.push_back(0);
        }
    }

    //ɾ������
    void removeVertex(int index)
    {
        if(index >= size())
        {
            throw out_of_range("���㲻����");
        }
        //�ڶ����б����Ƴ�����index�Ķ���
        vertices.erase(vertices.begin() + index);
        //���ڽӾ���ɾ����
        adjMat.erase(adjMat.begin() + index);
        //���ڽӾ���ɾ����
        for(vector<int> &row : adjMat)
        {
            row.erase(row.begin() + index);
        }
    }

    //��ӱ�
    //���� i ��j ��ӦverticesԪ������
    void addEdge(int i,int j)
    {
        //����Խ��
        if(i < 0 || j < 0 || i >= size() || j >= size() || i == j)
        {
            throw out_of_range("���㲻����");
        }

        //������ͼ�У��ڽӾ���������Խ��߶Գ�(i,j)=(j,i)
        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }

    //ɾ����
    //���� i ��j ��ӦverticesԪ������
    void removeEdge(int i,int j)
    {
        //����Խ��
        if(i < 0 || j < 0 || i >= size() || j >= size() || i == j)
        {
            throw out_of_range("���㲻����");
        }

        //������ͼ�У��ڽӾ���������Խ��߶Գ�(i,j)=(j,i)
        adjMat[i][j] = 0;
        adjMat[j][i] = 0;
    }

    //��ӡ�ڽӾ���
    void print()
    {
        cout<<"�����б� = ";
        printVector(vertices);
        cout << "�ڽӾ��� = "<< endl;
        printVectorMatrix(adjMat);
    }
};



int main()
{
    vector<int> vertices = {1, 3, 2, 5, 4};
    // �ߵ��б���ʾ�������������ӹ�ϵ
    vector<vector<int>> edges = {{0, 1}, {1, 2},{2,3},{3,4},{0,3},{2,4}};
    
    // ��������ͼ
    GraphAdjMat graph(vertices, edges);
    
    // ��ӡ������ڽӾ���
    graph.print();
}