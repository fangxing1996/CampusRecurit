#include<vector>
#include<iostream>
using namespace std;
#include<stdio.h>
class Solution{
    public:
        int numIslands(vector<vector<char>>& grid) {
            if(grid.size() == 0)
                return 0;
        int ans = 0;
        //获取行数和列数
        rows = grid.size();
        cols = grid[0].size();
        //初始化访问标记数组
        vector<vector<bool>> visited(rows, vector<bool>(cols, 0));
        //访问标志数组
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                //如果是陆地点且没有访问过就从这一点开始bfs广度优先搜索
                if(grid[i][j] == '1' && visited[i][j]==false)
                {
                    ans++;//岛屿计数加1
                    bfs(grid, visited, i, j);
                }
            }
        }
        return ans;
    }
private:
    int rows;//行数
    int cols;//列数
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)//广度优先搜索
    {
        if(i >= 0 && i < rows && j >= 0 && j < cols)//网格的边界条件，不能越界
        {
            if(grid[i][j] == '1' && visited[i][j] == false)
            {
                visited[i][j] = true;
                //四个邻接点递归bfs
                bfs(grid, visited, i + 1, j);
                bfs(grid, visited, i - 1, j);
                bfs(grid, visited, i, j - 1);
                bfs(grid, visited, i, j + 1);
            }
        }
    }
};
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid_(m);
    for(int i = 0; i < m; i++){
        grid_[i].resize(n);
    }
    for(int i = 0; i < grid_.size(); i++){
        for(int j = 0; j < grid_[0].size(); j++){
            cin >> grid_[i][j];
        }
    }
    Solution sol;
    vector<vector<char>> &g = grid_;
    cout << sol.numIslands(g);
    return 0;
}
