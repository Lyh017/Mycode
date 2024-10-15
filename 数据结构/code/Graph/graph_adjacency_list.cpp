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

//基于邻接表实现的无向图
class GraphAdjList
{
public:
    unordered_map<Vertex *,vector<Vertex *>> adjList;

    //在vector中删除指定节点
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


    //构造函数
    GraphAdjList(const vector<vector<Vertex *>> &edges)
    {
        for(const vector<Vertex *> &edge : edges)
        {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0],edge[1]);
        }
    }

    //获取顶点数量
    int size()
    {
        return adjList.size();
    }


    //添加边
    void addEdge(Vertex* vet1,Vertex* vet2)
    {
        if(!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
        {
            throw invalid_argument("不存在顶点");
        }
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }

    //删除边
    void removeEdge(Vertex *vet1,Vertex* vet2)
    {
        if(!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
        {
            throw invalid_argument("不存在顶点");
        }
        remove(adjList[vet1],vet2);
        remove(adjList[vet2],vet1);
    }

    //添加顶点
    void addVertex(Vertex* vet)
    {
        if(adjList.count(vet))
        {
            return;
        }
        //在邻接表中添加一个新链表
        adjList[vet] = vector<Vertex *>();
    }

    /* 删除顶点 */
    void removeVertex(Vertex *vet) {
        if (!adjList.count(vet))
            throw invalid_argument("不存在顶点");
        // 在邻接表中删除顶点 vet 对应的链表
        adjList.erase(vet);
        // 遍历其他顶点的链表，删除所有包含 vet 的边
        for (auto &adj : adjList) {
            remove(adj.second, vet);
        }
    }

    /* 打印邻接表 */
    void print() {
        cout << "邻接表 =" << endl;
        for (auto &adj : adjList) {
            const auto &key = adj.first;
            const auto &vec = adj.second;
            cout << key->val << ": ";
            printVector(vetsToVals(vec));
        }
    }
};


int main() {
    /* 初始化无向图 */
    vector<Vertex *> v = valsToVets(vector<int>{1, 3, 2, 5, 4});
    vector<vector<Vertex *>> edges = {{v[0], v[1]}, {v[0], v[3]}, {v[1], v[2]},
                                      {v[2], v[3]}, {v[2], v[4]}, {v[3], v[4]}};
    GraphAdjList graph(edges);
    cout << "\n初始化后，图为" << endl;
    graph.print();

    /* 添加边 */
    // 顶点 1, 2 即 v[0], v[2]
    graph.addEdge(v[0], v[2]);
    cout << "\n添加边 1-2 后，图为" << endl;
    graph.print();

    /* 删除边 */
    // 顶点 1, 3 即 v[0], v[1]
    graph.removeEdge(v[0], v[1]);
    cout << "\n删除边 1-3 后，图为" << endl;
    graph.print();

    /* 添加顶点 */
    Vertex *v5 = new Vertex(6);
    graph.addVertex(v5);
    cout << "\n添加顶点 6 后，图为" << endl;
    graph.print();

    /* 删除顶点 */
    // 顶点 3 即 v[1]
    graph.removeVertex(v[1]);
    cout << "\n删除顶点 3 后，图为" << endl;
    graph.print();

    // 释放内存
    for (Vertex *vet : v) {
        delete vet;
    }

    return 0;
}