// 67
// Add Binary
// https://leetcode.com//problems/add-binary/
class Solution {
public:
    string addBinary(string a, string b) {
        int i= a.size()-1, j= b.size()-1, carry =0;
        string c;
        while(i>=0 || j>=0)
        {
            int sum = (i>=0? a[i]-'0' : 0) + (j>=0 ? b[j]-'0' : 0) + carry;
            c.insert(c.begin(),sum%2+'0');
            carry = sum/2;
            i--;
            j--;
        }
        if(carry>0)
            c.insert(c.begin(),'1');
        return c;
    }
};