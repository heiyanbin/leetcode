// 43
// Multiply Strings
// https://leetcode.com//problems/multiply-strings/
class Solution {
public:
    string multiply(string num1, string num2) {
        string r(num1.size() + num2.size(), '0');
        int start = r.size() - 1;
        for (int i = num2.size() - 1; i >= 0; --i, --start) {
            if (num2[i] == '0') continue;
            int k = start, carry = 0;
            for (int j = num1.size() - 1; j >= 0; --j, --k) {
                int x = (num1[j] - '0') * (num2[i] - '0');
                r[k] += x % 10 + carry;
                carry = x / 10;
                while (r[k] > '9') {
                    r[k] -= 10;
                    carry += 1;
                }
            }
            r[k] += carry;
        }
        int i = 0;
        for (; i < r.size() && r[i] == '0'; ++i) ;
        if (i == r.size()) return "0";
        return string(r.begin() + i, r.end());
    }
};