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
                    bfs(grid, i, j);
                    count ++;
                }
            }
        }
        return count;
    }
    
    void bfs(vector<vector<char>> &grid, int i, int j) {
        queue<pair<int, int>> q;
        const pair<int, int> dirs[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(q.push(make_pair(i, j)), grid[i][j] = '2'; !q.empty(); q.pop()) {
            i = q.front().first;
            j = q.front().second;
            for (auto &d : dirs) {
                int ni = i + d.first, nj = j + d.second;
                if (ni < grid.size() && ni >= 0 && nj < grid[i].size() && nj >= 0 && grid[ni][nj] == '1') {
                    grid[ni][nj] = '2';
                    q.push(make_pair(ni, nj));
                }
            }
        }
    }
};