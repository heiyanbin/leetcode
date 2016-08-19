// 241
// Different Ways to Add Parentheses
// https://leetcode.com//problems/different-ways-to-add-parentheses/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
    	map<char, function<int(int, int)>> op = { { '+', [](int a, int b) {return a + b; } },
    	{ '-', [](int a, int b) {return a - b; } },
    	{ '*', [](int a, int b) {return a * b; } } };
    	
    	function<vector<int>(int, int)> help = [&](int l, int r) {
    		vector<int> ans;
    		int i = l;
    		for (; i < r; ++i) {
    			if (string("+-*").find(input[i]) != string::npos) {
    				auto lResult = help(l, i - 1);
    				auto rResult = help(i + 1, r);
    				for (auto a : lResult) {
    					for (auto b : rResult) {
    						ans.push_back(op[input[i]](a, b));
    					}
    				}
    			}
    		}
    		if (ans.empty()) ans.push_back(stoi(input.substr(l, r - l + 1)));
    		return ans;
    	};
    	
    	return help(0, input.size() - 1);
    }
};