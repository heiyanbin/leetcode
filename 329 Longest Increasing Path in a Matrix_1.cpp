// 329
// Longest Increasing Path in a Matrix
// https://leetcode.com//problems/longest-increasing-path-in-a-matrix/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int maxLen = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (memo[i][j] == -1) {
                    memo[i][j] = dfs(i, j, matrix, memo);
                }
                maxLen = max(memo[i][j], maxLen);
            }
        }
        return maxLen;
    }
    
private:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& memo) {
        if (memo[i][j] != -1) return memo[i][j];
        pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto &d : dirs) {
            int newI = i + d.first, newJ = j + d.second;
            if (newI >= matrix.size() || newI < 0 || newJ >= matrix[newI].size() || newJ < 0) continue;
            if (matrix[newI][newJ] > matrix[i][j]) {
                memo[i][j] = max(memo[i][j], dfs(newI, newJ, matrix, memo) + 1);
            }
        }
        if (memo[i][j] == -1) memo[i][j] = 1;
        return memo[i][j];
    }
};