// 91
// Decode Ways
// https://leetcode.com//problems/decode-ways/
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int f2 =1;
        int f1 = s[s.size()-1]=='0' ? 0 : 1;
        for(int i=s.size()-2;i>=0;i--)
        {
            if(s[i]=='0')
            {
                f2=f1;
                f1=0;
            }
            else if(stoi(s.substr(i,2))<27)
            {
                int tmp = f1+f2;
                f2=f1;
                f1=tmp;
            }
            else
                f2 =f1;
        }
        return f1;
    }
};