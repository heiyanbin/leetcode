// 45
// Jump Game II
// https://leetcode.com//problems/jump-game-ii/
class Solution {
public:
    int jump(int A[], int n) {
        int pos= 0,count=0;
        while(pos<n-1)
        {
            if(pos+A[pos]>=n-1) return count+1;
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
            count++;
        }
        return count;
    }
};