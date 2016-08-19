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
            for(int i=0;i<n;i++)
            {
                bool skip =false;
                for(int j=0;j<t;j++)
                {
                    if(x[j]==i || abs(i-x[j])==abs(t-j))
                    {
                        skip = true;
                        break;
                    }
                }
                if(skip) continue;
                x[t]= i;
                DFS(t+1, x, n);
            }
        }
    }
    vector<vector<string>> output;
};