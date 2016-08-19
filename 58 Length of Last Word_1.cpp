// 58
// Length of Last Word
// https://leetcode.com//problems/length-of-last-word/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        char prev=' ';
        int i=0, start=0, len =0;
        while(s[i])
        {
            if(s[i]!=' ' && prev==' ')
                start=i;
            if(s[i]!=' ' && (s[i+1]==' '|| s[i+1]=='\0'))
                len = i-start+1;
            prev=s[i];
            i++;
        }
        return len;
    }
};