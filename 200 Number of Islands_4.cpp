// 200
// Number of Islands
// https://leetcode.com//problems/number-of-islands/
class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int count = 0;
        
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count ++;
                }
            }
                
        return count;
    }
    
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i == grid.size() || i < 0 || j == grid[i].size() || j < 0) return;
        if (grid[i][j] != '1') return;
        grid[i][j] = '2';
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
    }
};