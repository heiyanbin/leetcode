// 150
// Evaluate Reverse Polish Notation
// https://leetcode.com//problems/evaluate-reverse-polish-notation/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> operand;
        for(auto token : tokens)
        {
            if(isOp(token))
            {
                int b = operand.back();
                operand.pop_back();
                int a = operand.back();
                operand.pop_back();
                operand.push_back(calc(token, a, b));
            }
            else
                operand.push_back(stoi(token));
        }
        return operand.back();
    }
    int calc(string op, int a, int b)
    {
        if(op=="+") return a+b;
        if(op=="-") return a-b;
        if(op=="*") return a*b;
        if(op=="/") return a/b;
        throw invalid_argument("");
    }
    bool isOp(const string &s)
    {
        return s.size()==1 && string("+-*/").find(s)!=string::npos;
    }
};