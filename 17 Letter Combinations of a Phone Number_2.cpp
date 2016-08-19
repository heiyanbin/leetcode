// 17
// Letter Combinations of a Phone Number
// https://leetcode.com//problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string x;
        DFS(0,0,x,digits);
        return output;
    }
    void DFS(int t, int i, string &x, string &digits)
    {
        if(t>=digits.length())
            output.push_back(x);
        else
        {
            if(digits[t] =='0' || digits[t]=='1')
                DFS(t+1,i,x,digits);
            else
            {
                for(auto letter : mp[digits[t]])
                {
                    if(x.size()<=i)
                        x.push_back(letter);
                    else
                        x[i]=letter;
                    DFS(t+1,i+1, x,digits);
                }
            }
        }
    }
private: 
    map<char,string> mp;
    vector<string> output;
};