// 17
// Letter Combinations of a Phone Number
// https://leetcode.com//problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    vector<string> letterCombinations(string& digits) {
        if (digits.empty()) return {};
		string m[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> res;
		string path;
		function<void(int)> dfs = [&](int t)->void {
			if (t == digits.size()) res.push_back(path);
			else {
				for (char c : m[digits[t] - '0']) {
					path.push_back(c);
					dfs(t + 1);
					path.pop_back();
				}
			}
		};
		dfs(0);
		return res;
	}
};