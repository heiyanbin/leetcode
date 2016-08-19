// 46
// Permutations
// https://leetcode.com//problems/permutations/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> output;
        permute(num, 0, output);
        return output;
    }
private:    
    void permute(vector<int> &num, int t,  vector<vector<int>> &output) {
        if (t == num.size()) 
            output.push_back(num);
        else {
            for (int i = t; i < num.size(); i++) {
                swap(num[t], num[i]);
                permute(num, t + 1, output);
                swap(num[t], num[i]);
            }
        }
    }
};