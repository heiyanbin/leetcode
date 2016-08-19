// 8
// String to Integer (atoi)
// https://leetcode.com//problems/string-to-integer-atoi/
class Solution {
public:
    int atoi(const char *str) {
        if(!str) return 0;
 
        while(*str && *str==' ')
            str++;
        bool negative = false;
        if(*str=='-')
        {
            negative = true;
            str++;
        }
        else if(*str=='+')
            str++;
        
        long long value =0;
        while(*str && isdigit(*str) && value<=INT_MAX)
        {
            value = value * 10 + *str -'0';
            str++;
        }
        value=  negative ? -value : value;
        value = value > INT_MAX ? INT_MAX :value;
        value = value < INT_MIN ? INT_MIN :value;
            
        return value;
    }
};