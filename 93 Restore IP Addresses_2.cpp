// 93
// Restore IP Addresses
// https://leetcode.com//problems/restore-ip-addresses/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.empty()) return output;
        vector<string> x(4);
        DFS(0, x, s, 0);
        return output;
    }
    void DFS(int t, vector<string> &x, string &s, int i)
    {
        if(i>=s.size() && t<4) return;
        if(t == 4)
        {
            if(i<s.size()) return;
            string ip;
            for_each(x.begin(),x.end(),[&ip](const string &part){ip.append(part+".");});
            output.push_back(ip.substr(0,ip.size()-1));
            return;
        }
        x[t]=s.substr(i,1);
        DFS(t+1,x,s,i+1);
        if(s[i]=='0') //don't include 0xx
            return ;
        if(s.size()-i>=2)
        {
            x[t]=s.substr(i,2);
            DFS(t+1,x,s,i+2);
        }
        if(s.size()-i>=3 && stoi(s.substr(i,3))<256)
        {
            x[t]=s.substr(i,3);
            DFS(t+1,x,s,i+3);
        }
    }
private:
    vector<string> output;
};