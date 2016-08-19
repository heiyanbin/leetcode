// 45
// Jump Game II
// https://leetcode.com//problems/jump-game-ii/
class Solution {
public:
    int jump(int A[], int n) {
        int last_reach=0, reach=0,count=0;
        for(int i=0;i<=last_reach && last_reach<n;)
        {
            reach=max(reach,i+A[i]);
            if(i==n-1) return count;
            i++;
            if(i>last_reach && i<=reach)
            {
                count++;
                last_reach=reach;
            }
        }
        return count;
    }
};