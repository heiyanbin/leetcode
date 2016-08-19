// 28
// Implement strStr()
// https://leetcode.com//problems/implement-strstr/
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!haystack||!needle) return NULL;
        int m= strlen(haystack);
        int n= strlen(needle);
        if(n>m) return NULL;
        for(int i=0;i<=m-n;i++)
        {
            int s=0, e=n-1;
            while(s<=e)
            {
                if(haystack[i+s]!=needle[s]) break;
                if(haystack[i+e]!=needle[e]) break;
                s++; e--;
            }
            if(s>e) return haystack+i;
        }
        return NULL;
    }
};