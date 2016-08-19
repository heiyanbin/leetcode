// 43
// Multiply Strings
// https://leetcode.com//problems/multiply-strings/
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> z(num1.size()+ num2.size());
        for(int i=num1.size()-1;i>=0;i--)
            for(int j=num2.size()-1;j>=0;j--)
            {
                z[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
                z[i+j]+=z[i+j+1]/10;
                z[i+j+1]=z[i+j+1]%10;
            }
        string s;
        transform(find_if(z.begin(),prev(z.end()),[](int i){return i>0;}), z.end(), back_inserter(s),[](int i){return i+'0';});
        return s;
    }
};