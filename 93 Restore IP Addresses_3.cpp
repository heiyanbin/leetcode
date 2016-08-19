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
        if(i>s.size()-1) return;
        if(t ==3)
        {
            if(s.size()-i>3 || (s[i]=='0' && i<s.size()-1)) //rule out digit number bigger than 3 and 0xx pattern
                return;
            string remainder = s.substr(i);
            if(stoi(remainder)<256)
            {
                x[t]=remainder;
                string ip;
                int k=0;
                for(int j=0;j<7;j++)
                {
                    if((j&1)==0)
                        ip.append(x[k++]);
                    else
                        ip.append(".");
                }
                output.push_back(ip);
            }
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
        if(s.size()-i>=3 && stol(s.substr(i,3))<256)
        {
            x[t]=s.substr(i,3);
            DFS(t+1,x,s,i+3);
        }
    }
private:
    vector<string> output;
};