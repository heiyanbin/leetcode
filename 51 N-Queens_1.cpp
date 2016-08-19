// 51
// N-Queens
// https://leetcode.com//problems/n-queens/
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> output;
        if (n < 1) return output;
        vector<int> x(n);
        function<void(int)> dfs = [&](int t) -> void {
            if (t >= n) {            
                vector<string> m(n, string(n, '.'));
                for (int i = 0; i < n; m[i][x[i]] = 'Q', i++) ;
                output.push_back(m);
            } else {
                for(int j = 0; j < n; j++) {
                    int i = 0;
                    for (; i < t && x[i] != j && abs(j - x[i]) != abs(t - i); i++) ;
                    if (i < t) continue;
                    x[t] = j;
                    dfs(t + 1);
                }
            }
        };
        dfs(0);
        return output;
    }
};