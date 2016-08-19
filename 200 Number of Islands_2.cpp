// 200
// Number of Islands
// https://leetcode.com//problems/number-of-islands/
class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count ++;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i == grid.size() || i < 0 || j == grid[i].size() || j < 0 || grid[i][j] != '1') return;
        grid[i][j] = '2';
        const pair<int, int> dirs[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto &d : dirs) dfs(grid, i + d.first, j + d.second);
    }
};