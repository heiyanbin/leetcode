// 8
// String to Integer (atoi)
// https://leetcode.com//problems/string-to-integer-atoi/
class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        for (; str[i] == ' '; ++i);
        if ( i == str.size()) return 0;
        int sign = 1;
        if (str[i] == '-') {
            sign = -1;
            ++i;
        } 
        else if (str[i] == '+')
            ++i;
        int value = 0;  
        for(; i < str.size() && isdigit(str[i]); ++i) {
            int d = str[i] - '0';
            if ((INT_MAX - d) / 10 >= value) value = value * 10 + d;
            else return sign > 0 ? INT_MAX : INT_MIN;
        }
        return sign * value;
    }
};