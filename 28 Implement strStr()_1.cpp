// 28
// Implement strStr()
// https://leetcode.com//problems/implement-strstr/
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if(!haystack || ! needle) return -1;
        int m = strlen(haystack),n=strlen(needle);
        if(m==0 && n==0) return 0;
        for(int i=0;i<=m-n;i++) {
            int j=0;
            for(;j<n && haystack[i+j]==needle[j];j++);
            if(j==n) return i;
        }
        return -1;
    }
};