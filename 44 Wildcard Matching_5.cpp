// 44
// Wildcard Matching
// https://leetcode.com//problems/wildcard-matching/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        assert(s && p);
        int n1= strlen(s), n2;
        string q = removeDupStar(p);
        n2= q.size();
        if(n2-count(q.begin(),q.end(),'*')>n1)
            return false;
        vector<bool> f1(n2+1,false);
        vector<bool> f2(n2+1,false);
        f1[0]=true;
        for(int j=1;j<=n2;j++)
        {
            f1[j]= f1[j-1] && q[j-1]=='*';
        }
        for(int i=1;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                if(j==0)
                {
                    f2[j]=false;
                }
                else
                {
                    if(f1[j-1] && (q[j-1]==s[i-1] || q[j-1]=='?'))
                        f2[j]= true;
                    else if( q[j-1]=='*' && (f1[j-1] || f2[j-1] || f1[j]))
                        f2[j]=true; 
                }
            }
            f1=f2;
            f2= vector<bool>(n2+1,false);
        }
        return f1[n2];
    }
    string removeDupStar( const char*p)
    {
        string q;
        for(int j=0;p[j];j++)
        {
            if(j==0 || p[j]!='*'|| q.back()!='*')
            {
                q.push_back(p[j]);
            }
        }
        return q;
    }
};