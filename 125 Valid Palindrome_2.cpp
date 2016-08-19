// 125
// Valid Palindrome
// https://leetcode.com//problems/valid-palindrome/
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        if(n<2) 
            return true;
        int i=0,j=n-1;
        while(i<j)
        {
            if(!isLetterOrDigit(s[i]))
                i++;
            else if(!isLetterOrDigit(s[j]))
                j--;
            else if(!equals(s[i],s[j]))
                return false;
            else
            {
                i++; j--;
            }
        }
        return true;
    }
    bool isLetterOrDigit(char c)
    {
        return c>='a' && c<='z' || c>='A' && c<='Z'||c>='0' && c<='9';
    }
    bool equals(char a, char b)
    {
        if(a<'a'&& a>'9')
            a+='a'-'A';
        if(b<'a'&& a>'9')
            b+='a'-'A';
        return a==b;
    }
};