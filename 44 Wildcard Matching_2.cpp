// 44
// Wildcard Matching
// https://leetcode.com//problems/wildcard-matching/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        assert(s && p);
        int n1= strlen(s), n2= strlen(p);
        if(n2-count(p,p+n2,'*')>n1)
            return false;
        vector<bool> f1(n2+1,false);
        vector<bool> f2(n2+1,false);
        f1[0]=true;
        for(int j=1;j<=n2;j++)
            f1[j]= f1[j-1] && p[j-1]=='*';
        for(int i=1;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                if(j==0)
                    f2[j]=false;
                else
                {
                    if(f1[j-1] && (p[j-1]==s[i-1] || p[j-1]=='?'))
                        f2[j]= true;
                    else if( p[j-1]=='*')
                    {
                        if(j-2>=0 && p[j-2]=='*')
                            f2[j]=f2[j-1];
                        else if(f1[j-1] || f2[j-1] || f1[j])
                            f2[j]=true; 
                    }
                    else
                        f2[j]=false;
                }
            }
            f1=f2;
        }
        return f1[n2];
    }
};