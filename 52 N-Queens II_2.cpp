// 52
// N-Queens II
// https://leetcode.com//problems/n-queens-ii/
class Solution {
public:
    int totalNQueens(int n) {
        if(n<2) return n;
        vector<int> x(n);
        int num =0;
        DFS(0,x,n,num);
        return num;
    }
    void DFS(int t, vector<int> &x, int n, int &num)
    {
        if(t>=n)
        {
            num++;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                bool skip = false;
                for(int j=0;j<t;j++)
                {
                    if(x[j]==i || abs(t-j)==abs(i-x[j]))
                    {
                        skip = true;
                        break;
                    }
                }
                if(skip) 
                    continue;
                x[t]=i;
                DFS(t+1,x,n,num);
            }
        }
    }
};