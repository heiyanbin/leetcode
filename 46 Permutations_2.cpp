// 46
// Permutations
// https://leetcode.com//problems/permutations/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> res;
        vector<bool> used(num.size(), false);
        vector<int> x;
        permute(num, used, x, res);
        return res;
    }
private:    
    void permute(vector<int> &num, vector<bool> &used, vector<int> &x, vector<vector<int>> &res) {
        if (x.size() == num.size()) 
            res.push_back(x);
        else {
            for (int i = 0; i < num.size(); ++ i) {
                if (used[i]) continue;
                x.push_back(num[i]);
                used[i] = true;
                permute(num, used, x, res);
                x.pop_back();
                used[i] = false;
            }
        }
    }
};