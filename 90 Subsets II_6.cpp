// 90
// Subsets II
// https://leetcode.com//problems/subsets-ii/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        int * x = new int[S.size()];
        v.push_back(vector<int>());
        sort(S.begin(),S.end());
        select(S,0,x,0);
        delete [] x;
        return v;
    }
    void select(vector<int> &S, int t, int x[], int start)
    {
        for(int i=start;i<S.size();i++)
        {
            bool skip = false;
            for(int j=start;j<i;j++)
            {
                if(S[j]==S[i])
                {   
                    skip= true;
                    break;
                }
            }
            if(skip) continue;
            x[t] = S[i];
            vector<int> xv=toVect(x,t);
            v.push_back(xv);
            select(S,t+1,x,i+1);
        }
    }
    vector<int> toVect(int x[],int endIndex)
    {
        vector<int> v;
        for(int i=0;i<=endIndex;i++)
            v.push_back(x[i]);
        return v;
    }
private:
    vector<vector<int>> v;
};