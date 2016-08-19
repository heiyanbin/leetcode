// 8
// String to Integer (atoi)
// https://leetcode.com//problems/string-to-integer-atoi/
class Solution {
public:
    int atoi(const char *str) {
        if(!str) return 0;
 
        while(*str && *str==' ')
            str++;
        if(!(*str)||(*str!='-' && *str!='+' && !isdigit(*str))) return 0;
        
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
        if(value>INT_MAX) 
            value = INT_MAX;
        if(value<INT_MIN)
            value = INT_MIN;
            
        return (int)value;
    }
};