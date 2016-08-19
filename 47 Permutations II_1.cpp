// 47
// Permutations II
// https://leetcode.com//problems/permutations-ii/
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> res;
        vector<bool> used(num.size(), false);
        sort(num.begin(), num.end());
        vector<int> x;
        permute(num, used, x, res);
        return res;
    }
    
    void permute(vector<int> &num, vector<bool> &used, vector<int> &x, vector<vector<int>> &res) {
        if (x.size() == num.size())
            res.push_back(x);
        else {
            for(int i = 0; i < num.size(); i++) {
                if (used[i] || i > 0 && num[i] == num[i - 1] && !used[i - 1]) continue;
                x.push_back(num[i]);
                used[i] = true;
                permute(num, used, x, res);
                x.pop_back();
                used[i] = false;
            }
        }
    }
};