// 67
// Add Binary
// https://leetcode.com//problems/add-binary/
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty()) return b;
        if(b.empty()) return a;
        int i= a.size()-1;
        int j= b.size()-1;
        string c;
        int carry =0;
        while(i>=0 && j>=0)
        {
            int sum = a[i]-'0'+ b[j]-'0'+carry;
            c.push_back(sum%2+'0');
            carry = sum/2;
            i--;
            j--;
        }
        while(i>=0)
        {
            int sum = a[i]-'0' + carry;
            c.push_back(sum%2+'0');
            carry = sum /2;
            i--;
        }
        while(j>=0)
        {
            int sum = b[j]-'0' + carry;
            c.push_back(sum%2+'0');
            carry = sum /2;
            j--;
        }
        if(carry>0)
            c.push_back('1');
        
        return string(c.rbegin(),c.rend());
    }
};