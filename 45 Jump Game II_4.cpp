// 45
// Jump Game II
// https://leetcode.com//problems/jump-game-ii/
class Solution {
public:
    int jump(int A[], int n) {
        int last_reach=0, reach=0,count=0;
        for(int i=0;i<n;i++)
        {
            if(i>last_reach)
            {
                last_reach= reach;
                count++;
            }
            reach=max(reach,i+A[i]);
        }
        return count;
    }
};