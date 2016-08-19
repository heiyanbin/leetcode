// 93
// Restore IP Addresses
// https://leetcode.com//problems/restore-ip-addresses/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        DFS(0, "", s, 0);
        return output;
    }
    void DFS(int t, string x, string &s, int i)
    {
        if(i>=s.size() && t<4) return;
        if(t == 4)
        {
            if(i<s.size()) return;
            output.push_back(x.substr(0,x.size()-1));
            return;
        }
        for(int l=1;l<=3;l++)
        {
            if(i+l-1>=s.size()) break;
            string part =s.substr(i,l);
            if(stoi(part)<256)
                DFS(t+1,x+part+".",s,i+l);
            if(s[i]=='0') break;
        }
    }
private:
    vector<string> output;
};