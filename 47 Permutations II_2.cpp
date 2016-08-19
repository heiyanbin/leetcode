// 47
// Permutations II
// https://leetcode.com//problems/permutations-ii/
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> res;
        permute(num, 0, res);
        return res;
    }
    
    void permute(vector<int> &num, int t, vector<vector<int>> &res) {
        if (t == num.size())
            res.push_back(num);
        else {
            for(int i = t; i < num.size(); i++) {
                if (find(num.begin() + t, num.begin() + i, num[i]) != num.begin() + i) continue;
                swap(num[t], num[i]);
                permute(num, t + 1, res);
                swap(num[t], num[i]);
            }
        }
    }
};