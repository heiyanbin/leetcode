// 89
// Gray Code
// https://leetcode.com//problems/gray-code/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> output;
        if(n==0) 
        {
            output.push_back(0);
            return output;
        }
        vector<string> v= gray(n);
        for(int i=0;i<v.size();i++)
        {
            int value =0;
            for(int j=0;j<v[i].size();j++)
                value=value *2 +v[i][j]-'0';
            output.push_back(value);
        }
        
        return output;
    }
    vector<string> gray(int n)
    {
        vector<string> output;
        if(n<=1)
        {
            output.push_back("0");
            output.push_back("1");
            return output;
        }
        vector<string> v = gray(n-1);
       // output= vector<string>(v.size()*2);
        for(int i=0;i<v.size();i++)
        {
            output.push_back('0'+v[i]);
        }
        for(int i=v.size()-1;i>=0;i--)
        {
            output.push_back('1'+v[i]);
        }
        return output;
    }
};