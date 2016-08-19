// 22
// Generate Parentheses
// https://leetcode.com//problems/generate-parentheses/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string x(n * 2, 0);
        function<void(int, int, int)> dfs = [&](int t, int l, int r) -> void {
            if (t == 2 * n) res.push_back(x);
            else {
                if (l < n) {
                    x[t] = '(';
                    dfs(t + 1, l + 1, r);
                }
                if (l > r) {
                    x[t] = ')';
                    dfs(t + 1, l, r + 1);
                }
            }
        };
        dfs(0, 0, 0);
        return res;
    }
};