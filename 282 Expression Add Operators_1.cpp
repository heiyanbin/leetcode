// 282
// Expression Add Operators
// https://leetcode.com//problems/expression-add-operators/
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        function<void(int, long long, long long, string)> dfs = [&](int i, long long eval, long long pre, string s)->void {
            if (i == num.size())  {
                if (target == eval) ans.push_back(s);
            }
            else {
                for (int j = i; j < num.size(); ++j) {
                    if (num[i] == '0' && j > i) break;
                    string cur = num.substr(i, j - i + 1);
                    long long value = stol(cur);
                    if (i == 0) {
                        dfs(j + 1, value, value, cur);
                    }
                    else {
                        dfs(j + 1, eval + value, value, s + "+" + cur);
                        dfs(j + 1, eval - value, -value, s + "-" + cur);
                        dfs(j + 1, eval - pre + value * pre, value * pre, s + "*" + cur);
                    }
                }
            }
        };
        dfs(0, 0, 0, "");
        return ans;
    }
};