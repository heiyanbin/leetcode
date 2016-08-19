// 52
// N-Queens II
// https://leetcode.com//problems/n-queens-ii/
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> x(n);
        int num =0;
        DFS(0,x,n,num);
        return num;
    }
    void DFS(int t, vector<int> &x, int n, int &num)
    {
        if(t>=n)
            num++;
        else
        {
            for(int j=0;j<n;j++)
            {
                int i=0;
                for(;i<t && x[i]!=j && abs(t-i)!=abs(j-x[i]);i++);
                if(i<t) continue;
                x[t]=j;
                DFS(t+1,x,n,num);
            }
        }
    }
};