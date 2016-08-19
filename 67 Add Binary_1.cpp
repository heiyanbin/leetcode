// 67
// Add Binary
// https://leetcode.com//problems/add-binary/
class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        for(int i= a.size()-1, j= b.size()-1, carry =0, sum= 0;i>=0 || j>=0 || carry; carry = sum/2,i--,j--)
        {
            sum = (i>=0? a[i]-'0' : 0) + (j>=0 ? b[j]-'0' : 0) + carry;
            c.insert(c.begin(),sum%2+'0');
        }
        return c;
    }
};