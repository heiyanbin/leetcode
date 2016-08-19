// 273
// Integer to English Words
// https://leetcode.com//problems/integer-to-english-words/
class Solution {
public:
	string numberToWords(int num) {
		string s = to_string(num);
		const string unit[] = { "", " Thousand", " Million", " Billion" };
		vector<string> v;
		for (int i = s.size() - 1, j = 0; i >= 0; i -= 3, ++j) {
			string x = help(s, i - 2, i);
			if (!x.empty()) v.push_back(x + unit[j]);
		}
		string ans;
		for (int i = v.size() - 1; i >= 0; --i) {
			if (i < v.size() - 1) ans.push_back(' ');
			ans.append(v[i]);
		}
		return ans.empty() ? "Zero" : ans;
	}
private:
	string help(string &s, int start, int end) {
		if (start < 0) start = 0;
		const string m1[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" },
					m2[] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" },
					m3[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
		if (end == start) return m1[s[start] - '0'];
		if (end == start + 1) {
			if (s[start] == '0') return m1[s[end] - '0'];
			if (s[start] == '1') return m2[s[end] - '0'];
			return  m3[s[start] - '0'] + (m1[s[end] - '0'].empty() ? "" : " " + m1[s[end] - '0']);
		}
		if (end == start + 2) {
			if (s[start] == '0') return help(s, start + 1, end);
			auto x = help(s, start + 1, end);
			return m1[s[start] - '0'] + " Hundred" + (x.empty() ? x : " " + x);
		}
		throw exception();
	}
};