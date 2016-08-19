// 60
// Permutation Sequence
// https://leetcode.com//problems/permutation-sequence/
class Solution {
public:
    string getPermutation(int n, int k) 
    {
        assert(k>0);
        string s;
        for(int i=1;i<=n;i++)
            s.push_back('0'+i);
        string output;
        int f= fac(n);
        k--;
        for(int i=0;i<n;i++)
        {
            f=f/(n-i);
            int m=k/f;
            output.push_back(s[m]);
            s.erase(m,1);
            k=k%f;
        }
        return output;
    }
    int fac(int n)
    {
        int v = 1;
        for(int i=2;i<=n;i++)
            v*=i;
        return v;
    }
};