#include<iostream>
#include<vector>
using namespace std;

class Solution
{
private:
    vector<vector<string>> result;
    // n为输入棋盘的大小
    // row表示当前递归到棋盘的第几行了
    void backtracking(int n,int row,vector<string>& chessboard){
        if(row == n)
        {
            result.push_back(chessboard);
            return;
        }
        for(int col = 0;col<n;col++)
        {
            if(isValid(row,col,chessboard,n))
            {
                chessboard[row][col] = 'Q';
                backtracking(n,row+1,chessboard);
                chessboard[row][col] = '.'; //回溯，撤销皇后
            }
        }
    }

    bool isValid(int row,int col,vector<string>& chessboard,int n)
    {
        for(int i = 0;i<row;i++)
        {
            if(chessboard[i][col] == 'Q')
            {
                return false;
            }

        }
        //检查45度
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }

        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) 
        {
        if (chessboard[i][j] == 'Q') 
        {
            return false;
        }
        }   
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        std::vector<std::string> chessboard(n, std::string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};

int main() {
    Solution solution;
    int n = 4; 

    // 解决n皇后问题
    std::vector<std::vector<std::string>> solutions = solution.solveNQueens(n);

    // 打印所有的解决方案
    for (const auto& chessboard : solutions) {
        for (const auto& row : chessboard) {
            std::cout << row << std::endl;
        }
        std::cout << std::endl; // 每个解决方案之后打印一个空行
    }

    std::cout << "Number of solutions: " << solutions.size() << std::endl;

    return 0;
}