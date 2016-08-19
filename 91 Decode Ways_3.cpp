// 91
// Decode Ways
// https://leetcode.com//problems/decode-ways/
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        return numDecodings(s,0);
    }
    
   int numDecodings(string &s, int t)
    {
        if(memo.find(t)!=memo.end()) return memo[t];
        if(t>=s.length()) return 1;
        if(s[t]=='0') return 0;
        int n= numDecodings(s,t+1);
        if(t+1<s.size() && stoi(s.substr(t,2))<27 && stoi(s.substr(t,2))>0 )
            n += numDecodings(s,t+2);
        return memo[t]=n;
    }
    unordered_map<int,int> memo;
};