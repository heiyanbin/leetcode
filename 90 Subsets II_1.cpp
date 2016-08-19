// 90
// Subsets II
// https://leetcode.com//problems/subsets-ii/
class Solution{
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> A, count; //unique elements and count
        for (int i = 0; i < S.size(); i++) {
            if (i == 0 || S[i] != S[i - 1]) {
                A.push_back(S[i]);
                count.push_back(1);
            } else {
                count.back()++;
            }
        }
        vector<int> x;
        select(A, count, 0, x);
        return res;
    }
private:
    void select(vector<int> &A, vector<int> &count, int t, vector<int> &x) {
        if (t == A.size())
            res.push_back(x);
        else {
            for (int i = 0; i <= count[t]; ++ i) {
                for (int j = 0; j < i; ++ j) x.push_back(A[t]);
                select(A, count, t + 1, x);
                for (int j = 0; j < i; ++ j) x.pop_back();
            }
        }
    }
    vector<vector<int>> res;
};