// 46
// Permutations
// https://leetcode.com//problems/permutations/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return perm(nums, nums.size());
    }
private:
    vector<vector<int>> perm(vector<int> &A, int i) {
        if (i == 0) return {{}};
        auto l = perm(A, i - 1);
        vector<vector<int>> ans;
        for (auto &p : l) {
            for (int k = p.size(); k >= 0; --k) {
                auto q = p;
                q.insert(begin(q) + k, A[i - 1]);
                ans.push_back(q);
            }
        }
        return ans;
    }
};