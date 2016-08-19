// 55
// Jump Game
// https://leetcode.com//problems/jump-game/
class Solution {
public:
    bool canJump(int A[], int n) {
        if(n<=1) return true;
        vector<bool> d(n);
        d[0]=true;
        for(int i=1;i<n;i++)
        {
            d[i]=false;
            for(int j=0;j<i;j++)
            {
                if(d[j] && A[j]>=i-j)
                {
                    d[i]=true;
                    break;
                }
            }
        }
        return d[n-1];
    }
};