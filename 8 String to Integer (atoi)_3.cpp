// 8
// String to Integer (atoi)
// https://leetcode.com//problems/string-to-integer-atoi/
class Solution {
public:
    int atoi(const char *str) {
        if(!str) return 0;
        while(*str && *str==' ')str++;
        bool negative = false;
        if(*str=='-'){
            negative = true;
            str++;
        }
        else if(*str=='+')
            str++;
        int value = 0, maxdiv10 = INT_MAX/10,last_digit_max=INT_MAX%10;
        while(*str && isdigit(*str)) {
            if(value>maxdiv10 || value==maxdiv10 && *str-'0'>last_digit_max)
                return negative ? INT_MIN : INT_MAX;
            value = value * 10 + *str -'0';
            str++;
        }
        return negative ? -value : value;
    }
};