// 77
// Combinations
// https://leetcode.com//problems/combinations/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> x(k);
        select(0,x,1,n);
        return output;
    }
    void select(int t, vector<int> &x, int start , int end)
    {
        if(t==x.size())
            output.push_back(x);
        else {
            for(int i=start;i<=end;i++) {
                x[t]=i;
                select(t+1, x, i+1, end);
            }
        }
    }
private:
    vector<vector<int>> output;
};