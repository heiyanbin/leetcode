// 216
// Combination Sum III
// https://leetcode.com//problems/combination-sum-iii/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int>> res;
        dfs(k, 1, n, path, res);
        return res;
    }
    void dfs(int k, int start, int sum, vector<int> &path, vector<vector<int>> &res) {
        if (k == 0) {
            if (sum == 0) res.push_back(path);
        }
        else {
            for (int i = start; i <= 9 && i <= sum; i++) {
                path.push_back(i);
                dfs(k - 1, i + 1, sum - i, path, res);
                path.pop_back();
            }
        }
    }
};