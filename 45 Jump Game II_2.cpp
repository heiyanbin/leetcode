// 45
// Jump Game II
// https://leetcode.com//problems/jump-game-ii/
class Solution {
public:
    int jump(int A[], int n) {
        if(n<=1) return 0;
        int count=0,reach=0,next =0;
        for(int i=0;i<=reach;++i)
        {
            next = max(next,i+A[i]);
            if(i==reach)
            {
                count++;
                reach = next;
            }
            if(reach>=n-1) break;
        }
        return reach>=n-1? count : -1 ;
    }
};