#include<iostream>
#include<vector>
using namespace std;

// 基于邻接矩阵实现的无向类图
class GraphAdjMat{
private:
    vector<int> vertices;   //顶点列表，元素代表‘顶点值’，索引代表顶点索引
    vector<vector<int>> adjMat;  //邻接矩阵，行列索引对应顶点索引

public:
    //构造函数
    GraphAdjMat(const vector<int> &vertices,const vector<vector<int>> &edges)
    {
        //添加顶点
        for(int val : vertices)
        {
            addVertex(val);
        }

        //添加边
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
            printVector(row);  // 调用 printVector 打印每一行
        }
    }

    void addVertex(int val)
    {
        int n = size();
        // 向顶点列表中添加新顶点的值
        vertices.push_back(val);
        // 在邻接矩阵中添加一行
        adjMat.emplace_back(vector<int>(n, 0));
        // 在邻接矩阵中添加一列
        for (vector<int> &row : adjMat) {
            row.push_back(0);
        }
    }

    //删除顶点
    void removeVertex(int index)
    {
        if(index >= size())
        {
            throw out_of_range("顶点不存在");
        }
        //在顶点列表中移除索引index的顶点
        vertices.erase(vertices.begin() + index);
        //在邻接矩阵删除行
        adjMat.erase(adjMat.begin() + index);
        //在邻接矩阵删除列
        for(vector<int> &row : adjMat)
        {
            row.erase(row.begin() + index);
        }
    }

    //添加边
    //参数 i ，j 对应vertices元素索引
    void addEdge(int i,int j)
    {
        //索引越界
        if(i < 0 || j < 0 || i >= size() || j >= size() || i == j)
        {
            throw out_of_range("顶点不存在");
        }

        //在无向图中，邻接矩阵关于主对角线对称(i,j)=(j,i)
        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }

    //删除边
    //参数 i ，j 对应vertices元素索引
    void removeEdge(int i,int j)
    {
        //索引越界
        if(i < 0 || j < 0 || i >= size() || j >= size() || i == j)
        {
            throw out_of_range("顶点不存在");
        }

        //在无向图中，邻接矩阵关于主对角线对称(i,j)=(j,i)
        adjMat[i][j] = 0;
        adjMat[j][i] = 0;
    }

    //打印邻接矩阵
    void print()
    {
        cout<<"顶点列表 = ";
        printVector(vertices);
        cout << "邻接矩阵 = "<< endl;
        printVectorMatrix(adjMat);
    }
};



int main()
{
    vector<int> vertices = {1, 3, 2, 5, 4};
    // 边的列表，表示顶点索引的连接关系
    vector<vector<int>> edges = {{0, 1}, {1, 2},{2,3},{3,4},{0,3},{2,4}};
    
    // 创建无向图
    GraphAdjMat graph(vertices, edges);
    
    // 打印顶点和邻接矩阵
    graph.print();
}