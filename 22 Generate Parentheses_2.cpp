// 22
// Generate Parentheses
// https://leetcode.com//problems/generate-parentheses/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        if(n<=0) return v;
        string x(2*n,0);
        generate(0,n,x,0,0,v);
        return v;
    }
    void generate(int t, int n, string &x, int leftCount, int rightCount, vector<string> &v)
    {
        if(t>=2*n)
        {
            v.push_back(x);
        }
        else
        {
            if(leftCount<n)
            {
                x[t]='(';
                generate(t+1,n,x,leftCount+1,rightCount,v);
            }
            if(rightCount<leftCount)
            {
                x[t]=')';
                generate(t+1,n,x,leftCount,rightCount+1,v);
            }
        }
    }
};