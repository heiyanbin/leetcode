// 51
// N-Queens
// https://leetcode.com//problems/n-queens/
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        if(n<1) return output;
        vector<int> x(n);
        DFS(0,x,n);
        return output;
    }
    void DFS(int t, vector<int> &x, int n)
    {
        if(t>=n)
        {            
            vector<string> matrix;
            for(int i=0;i<n;i++)
            {
                string line(n,'.');
                line[x[i]]='Q';
                matrix.push_back(line);
            }
            output.push_back(matrix);
        }
        else
        {
            for(int j=0;j<n;j++)
            {
                int i=0;
                while(i<t && x[i]!=j && abs(j-x[i])!=abs(t-i))
                    i++;
                if(i<t) continue;
                x[t]= j;
                DFS(t+1, x, n);
            }
        }
    }
    vector<vector<string>> output;
};