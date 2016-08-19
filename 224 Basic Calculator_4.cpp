// 224
// Basic Calculator
// https://leetcode.com//problems/basic-calculator/
class Solution {
public:
    int calculate(string s) {
		stack<int> oprand;
		stack<char> op;
		oprand.push(0);
		op.push('+');
		for (int i = 0; i < s.length();) {
			if (s[i] == '+' || s[i] == '-' || s[i] == '(')
				op.push(s[i++]);
			else if (s[i] == ')') {
				op.pop();
				int v = oprand.top();
				oprand.pop();
				if (op.top() == '+') oprand.top() += v;
				else oprand.top() -= v;
				op.pop();
				++i;
			}
			else if (isdigit(s[i])) {
				int v = 0;
				for (; isdigit(s[i]); ++i) v = v * 10 + s[i] - '0';
				if (op.top() != '(') {
					if (op.top() == '+') oprand.top() += v;
					else oprand.top() -= v;
					op.pop();
				}
				else {
					oprand.push(v);
				}
			}
			else ++i;
		}
		if (oprand.size() > 0) return oprand.top();
		return 0;
	}
    
};