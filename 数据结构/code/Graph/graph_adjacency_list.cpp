#include "vertex.hpp"
#include<iostream>
#include<unordered_map>

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

//�����ڽӱ�ʵ�ֵ�����ͼ
class GraphAdjList
{
public:
    unordered_map<Vertex *,vector<Vertex *>> adjList;

    //��vector��ɾ��ָ���ڵ�
    void remove(vector<Vertex *>& vec, Vertex* vet)
    {
        for(size_t i = 0;i < vec.size();i++)
        {
            if(vec[i] == vet)
            {
                vec.erase(vec.begin() + i);
                break;
            }
        }
    }


    //���캯��
    GraphAdjList(const vector<vector<Vertex *>> &edges)
    {
        for(const vector<Vertex *> &edge : edges)
        {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0],edge[1]);
        }
    }

    //��ȡ��������
    int size()
    {
        return adjList.size();
    }


    //��ӱ�
    void addEdge(Vertex* vet1,Vertex* vet2)
    {
        if(!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
        {
            throw invalid_argument("�����ڶ���");
        }
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }

    //ɾ����
    void removeEdge(Vertex *vet1,Vertex* vet2)
    {
        if(!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
        {
            throw invalid_argument("�����ڶ���");
        }
        remove(adjList[vet1],vet2);
        remove(adjList[vet2],vet1);
    }

    //��Ӷ���
    void addVertex(Vertex* vet)
    {
        if(adjList.count(vet))
        {
            return;
        }
        //���ڽӱ������һ��������
        adjList[vet] = vector<Vertex *>();
    }

    /* ɾ������ */
    void removeVertex(Vertex *vet) {
        if (!adjList.count(vet))
            throw invalid_argument("�����ڶ���");
        // ���ڽӱ���ɾ������ vet ��Ӧ������
        adjList.erase(vet);
        // �����������������ɾ�����а��� vet �ı�
        for (auto &adj : adjList) {
            remove(adj.second, vet);
        }
    }

    /* ��ӡ�ڽӱ� */
    void print() {
        cout << "�ڽӱ� =" << endl;
        for (auto &adj : adjList) {
            const auto &key = adj.first;
            const auto &vec = adj.second;
            cout << key->val << ": ";
            printVector(vetsToVals(vec));
        }
    }
};


int main() {
    /* ��ʼ������ͼ */
    vector<Vertex *> v = valsToVets(vector<int>{1, 3, 2, 5, 4});
    vector<vector<Vertex *>> edges = {{v[0], v[1]}, {v[0], v[3]}, {v[1], v[2]},
                                      {v[2], v[3]}, {v[2], v[4]}, {v[3], v[4]}};
    GraphAdjList graph(edges);
    cout << "\n��ʼ����ͼΪ" << endl;
    graph.print();

    /* ��ӱ� */
    // ���� 1, 2 �� v[0], v[2]
    graph.addEdge(v[0], v[2]);
    cout << "\n��ӱ� 1-2 ��ͼΪ" << endl;
    graph.print();

    /* ɾ���� */
    // ���� 1, 3 �� v[0], v[1]
    graph.removeEdge(v[0], v[1]);
    cout << "\nɾ���� 1-3 ��ͼΪ" << endl;
    graph.print();

    /* ��Ӷ��� */
    Vertex *v5 = new Vertex(6);
    graph.addVertex(v5);
    cout << "\n��Ӷ��� 6 ��ͼΪ" << endl;
    graph.print();

    /* ɾ������ */
    // ���� 3 �� v[1]
    graph.removeVertex(v[1]);
    cout << "\nɾ������ 3 ��ͼΪ" << endl;
    graph.print();

    // �ͷ��ڴ�
    for (Vertex *vet : v) {
        delete vet;
    }

    return 0;
}