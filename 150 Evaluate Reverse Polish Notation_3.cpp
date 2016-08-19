// 150
// Evaluate Reverse Polish Notation
// https://leetcode.com//problems/evaluate-reverse-polish-notation/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.size()==1) return atoi(tokens[0].c_str());
        vector<int> operand;
        for(vector<string>::iterator it= tokens.begin();it!=tokens.end();it++)
        {
            if(isOp(*it))
            {
                int b = operand.back();
                operand.pop_back();
                int a = operand.back();
                operand.pop_back();
                operand.push_back(calc(*it, a, b));
            }
            else
            {
                operand.push_back(atoi((*it).c_str()));
            }
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
    bool isOp(string s)
    {
        return s=="+" || s=="-" || s=="*" || s=="/";
    }
};