// 224
// Basic Calculator
// https://leetcode.com//problems/basic-calculator/
class Solution {
public:
    int calculate(string s) {
        map<char, function<int(int,int)>> m = {{'+', [](int a, int b) {return a + b;}}, {'-', [](int a, int b){return a - b;}}};
		stack<int> oprand;
		stack<char> op;
		for (int i = 0; i < s.length();) {
		    if (isdigit(s[i])) {
				int v = 0;
				for (; isdigit(s[i]); ++i) v = v * 10 + s[i] - '0';
				if (!op.empty() && op.top() != '(') {
					oprand.top() = m[op.top()](oprand.top(), v);
					op.pop();
				}
				else oprand.push(v);
			}
			else if (string("+-(").find(s[i]) != string::npos) op.push(s[i++]);
			else if (s[i] == ')') {
			    op.pop();
                if (!op.empty() && op.top() != '(') {
                    int b = oprand.top(); oprand.pop();
                    oprand.top() = m[op.top()](oprand.top(), b);
                    op.pop();
                }
                ++i;
			}
			else ++i;
		}
		if (!oprand.empty()) return oprand.top();
		return 0;
	}
    
};