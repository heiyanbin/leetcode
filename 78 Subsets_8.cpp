// 78
// Subsets
// https://leetcode.com//problems/subsets/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> v;
        v.push_back(vector<int>());
        sort(S.begin(), S.end());
        int *x = new int[S.size()];
        subsets(S,0,x,0,v);
        delete [] x;
        return v;
    }
    
    void subsets(vector<int> &S, int t, int x[], int start, vector<vector<int>> &v)
    {
        for(int i=start;i<S.size();i++)
        {
            x[t]=S[i];
            vector<int> xv;
            for(int j=0;j<=t;j++)
            {
                xv.push_back(x[j]);
            }
            v.push_back(xv);
            subsets(S,t+1,x,i+1,v);
        }
    }
};