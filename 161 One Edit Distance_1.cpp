// 161
// One Edit Distance
// https://leetcode.com//problems/one-edit-distance/
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size()>t.size()) return isOneEditDistance(t,s);
        if(s.size()==t.size())
        {
            int count =0;
            for(int i=0;i<s.size();++i)
                if(s[i]!=t[i])
                {
                    count++;
                    if(count>1) return false;
                }
            return count==1;
        }
        else if(t.size()-s.size()>1) return false;
        else
        {
            int i=0;
            for(;i<s.size() && s[i]==t[i];++i);
            if(i==s.size()) return true;
            for(;i<s.size();++i)
                if(s[i]!=t[i+1]) return false;
            return true;
        }
    }
};