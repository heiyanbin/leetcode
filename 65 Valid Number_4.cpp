// 65
// Valid Number
// https://leetcode.com//problems/valid-number/
class Solution {
public:
    bool isNumber(const char *s) {
        if(s==NULL) return false;
        auto t = s;
        bool isNum = false;
        while(*s==' ')
            s++;
        if(*s==0) return false;
        if(*s=='-'||*s=='+')
            s++;
        while(isdigit(*s))
        {
            s++;
            isNum=true;
        }
        if(*s==' '||*s==0)
        {
            while(*s==' ') s++;
            return *s==0 && isNum;
        }
        if(*s!='.'&&*s!='e'&&*s!='E') return false;
        if(*s=='.')
        {
            s++;
            if(*s==' '||*s==0)
            {
                while(*s==' ') s++;
                return *s==0 && isNum;
            }
            while(isdigit(*s)) {s++;isNum=true;};
            if(*s==' '||*s==0)
            {
                while(*s==' ') s++;
                return *s==0 && isNum;
            }
            if(*s!='e'&&*s!='E'||!isNum) return false;
            s++;
            if(*s=='-'||*s=='+') s++;
            return allNumber(s);
        }
        else
        {
            if(!isNum) return false;
            s++;
            if(*s=='-'||*s=='+') s++;
            return allNumber(s);
        }
    }
    bool allNumber(const char*s)
    {
        if(!isdigit(*s)) return false;
        while(isdigit(*s)) s++;
        while(*s==' ')s++;
        return *s==0;
    }
};