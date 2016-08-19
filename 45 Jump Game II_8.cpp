// 45
// Jump Game II
// https://leetcode.com//problems/jump-game-ii/
class Solution {
public:
    int jump(int A[], int n) {
        if(n<=1) return 0;
        int count=0, i=0;
        while(i<n-1)
        {
            int nextFarest = -1, next =-1;
            if(i+A[i]>=n-1) 
                i=n-1;
            else
            {
                for(int reach=i+A[i];reach>i;reach--)
                {
                    if(reach+A[reach]> nextFarest )
                    {
                        nextFarest= reach+A[reach];
                        next = reach;
                    }
                }
                i=next;
            }
            count++;
        }
        return count;
    }
};