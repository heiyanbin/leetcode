// 77
// Combinations
// https://leetcode.com//problems/combinations/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        assert(n>0 && k<=n);
        int *x = new int[k];
        select(0,x,1,n,k);
        delete[] x;
        return output;
    }
    void select(int t, int x[], int startNum , int n, int k)
    {
        if(t>=k)
        {
            output.push_back(toVect(x,t));
        }
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
    vector<int> toVect(int x[], int n)
    {
        vector<int> v;
        for(int i=0;i<n;i++)
            v.push_back(x[i]);
        return v;
    }
};