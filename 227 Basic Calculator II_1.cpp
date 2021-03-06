// 227
// Basic Calculator II
// https://leetcode.com//problems/basic-calculator-ii/
class Solution {
public:
    int calculate(string s) {
		map<char, function<int(int, int)>> m = {
			{ '+', [](int a, int b) -> int { return a + b; } },
			{ '-', [](int a, int b) -> int { return a - b; } },
			{ '*', [](int a, int b) -> int { return a * b; } },
			{ '/', [](int a, int b) -> int { return a / b; } } };
		
		stack<char> op;
		stack<int> oprand;
		s.push_back('#');
		for (int i = 0; i < s.length(); ) {
			if (isdigit(s[i])) {
				int value = 0;
				for (; isdigit(s[i]); ++i) value = value * 10 + s[i] - '0';
				oprand.push(value);
			}
			else if (string("+-*/#").find(s[i]) != string::npos) {
				while (!op.empty() && (string("#+-").find(s[i]) != string::npos || op.top() == '*' || op.top() == '/')) {
					int b = oprand.top(); oprand.pop();
					oprand.top() = m[op.top()](oprand.top(), b);
					op.pop();
				}
				op.push(s[i++]);
			}
			else
				++i;
		}
		if (oprand.empty()) return 0;
		return oprand.top();
	}
    
};