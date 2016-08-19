// 224
// Basic Calculator
// https://leetcode.com//problems/basic-calculator/
class Solution {
public:
    int calculate(string s) {
        map<char, function<int(int,int)>> m = {{'+', [](int a, int b) {return a + b;}}, {'-', [](int a, int b){return a - b;}}};
		stack<int> oprand;
		stack<char> op;
		s.push_back('#');
		for (int i = 0; i < s.length();) {
			if (isdigit(s[i])) {
			    int value = 0;
			    for (; isdigit(s[i]); ++i) value = value * 10 + s[i] - '0';
			    oprand.push(value);
			} 
			else if (s[i] != ' ') {
			    while (!op.empty() && s[i] != '(' && op.top() != '(') {
			        int b = oprand.top(); oprand.pop();
			        oprand.top() = m[op.top()](oprand.top(), b);
			        op.pop();
			    }
			    if (s[i] == ')') op.pop();
			    else op.push(s[i]);
			    ++i;
			}
			else ++i;
		}
		if (!oprand.empty()) return oprand.top();
		return 0;
	}
    
};