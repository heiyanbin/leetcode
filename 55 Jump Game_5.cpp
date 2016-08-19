// 55
// Jump Game
// https://leetcode.com//problems/jump-game/
class Solution {
public:
    bool canJump(int A[], int n) {
        int pos= 0;
        while(pos<n-1)
        {
            if(A[pos]==0) return false;
            if(pos+A[pos]>=n-1) return true;
            int reach =0, nextPos=0;
            for(int step=1;step<=A[pos];step++)
            {
                if(step+A[pos+step]>reach)
                {
                    reach=step+A[pos+step];
                    nextPos=pos+step;
                }
            }
            pos=nextPos;
        }
        return true;
    }
};
