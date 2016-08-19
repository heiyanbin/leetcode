// 77
// Combinations
// https://leetcode.com//problems/combinations/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> x(k);
        select(0,x,1,n,k);
        return output;
    }
    void select(int t, vector<int> &x, int startNum , int n, int k)
    {
        if(t>=k)
            output.push_back(x);
        else
        {
            for(int i=startNum;i<=n;i++)
            {
                x[t]=i;
                select(t+1, x, i+1, n, k);
            }
        }
    }
private:
    vector<vector<int>> output;
};