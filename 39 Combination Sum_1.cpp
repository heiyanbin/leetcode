// 39
// Combination Sum
// https://leetcode.com//problems/combination-sum/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> x;
        sort(begin(candidates), end(candidates));
        function<void(int, int)> dfs = [&](int start, int sum) -> void {
            if (sum == 0) ans.push_back(x);
            else {
                for (int i = start; i < candidates.size(); ++i) {
                    if (candidates[i] > sum) break;
                    x.push_back(candidates[i]);
                    dfs(i, sum - candidates[i]);
                    x.pop_back();
                }
            }
        };
        dfs(0, target);
        return ans;
    }
};