// 140
// Word Break II
// https://leetcode.com//problems/word-break-ii/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		vector<vector<int>> pre(s.size() + 1);
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					dp[i] = true;
					pre[i].push_back(j);
				}
			}
		}
		vector<string> ans;
		function<void(int, string)> dfs = [&](int i, string path)->void {
			if (i == 0) ans.push_back(path);
			else
				for (int j : pre[i]) dfs(j, s.substr(j, i - j) + (path.empty() ? "" : ' ' + path));
		};
		dfs(s.size(), "");
		return ans;
    }
};