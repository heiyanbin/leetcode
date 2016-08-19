// 45
// Jump Game II
// https://leetcode.com//problems/jump-game-ii/
class Solution {
public:
    int jump(int A[], int n) {
        if(n<=1) return 0;
        int last_reach=0, reach=0,count=0;
        for(int i=0;i<=reach;i++)
        {
            if(i>last_reach)
            {
                last_reach= reach;
                count++;
            }
            reach=max(reach,i+A[i]);
            if(reach>=n-1) return count+1;
        }
        return reach>=n-1 ? count : -1;
    }
};