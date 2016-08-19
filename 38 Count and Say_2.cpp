// 38
// Count and Say
// https://leetcode.com//problems/count-and-say/
class Solution {
public:
    string countAndSay(int n) {
        string s="1", s2;
        for(int i=2;i<=n;i++)
        {
            int count =1;
            char prev =s[0];
            for(int i=1;i<=s.length();i++)
            {
                if(i==s.length())
                {
                    s2+=to_string(count)+prev;
                }
                else if(s[i]!=prev)
                {
                    s2+=to_string(count)+prev;
                    prev=s[i];
                    count=1;
                }
                else
                    count++;
            }
            s=s2;
            s2="";
        }
        return s;
    }
};