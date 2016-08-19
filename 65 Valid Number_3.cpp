// 65
// Valid Number
// https://leetcode.com//problems/valid-number/
class Solution {
public:
    bool isNumber(const char *s) {
        if(s==NULL) return false;
        while(*s==' ') s++;
        if(*s=='-'||*s=='+')s++;
        bool isNum = false;
        while(isdigit(*s)) {
            s++;
            isNum=true;
        }
        if(*s=='.') {
            s++;
            while(isdigit(*s)) {
                s++;
                isNum=true;
            };
        }
        if(isNum && *s=='e') {
            s++;
            isNum = false;
            if(*s=='-'||*s=='+') s++;
            while(isdigit(*s)) {
                s++;
                isNum = true;
            }
        }
        while(*s==' ') s++;
        return isNum && *s==0;
    }
};