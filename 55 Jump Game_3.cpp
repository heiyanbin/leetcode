// 55
// Jump Game
// https://leetcode.com//problems/jump-game/
class Solution {
public:
    bool canJump(int A[], int n) {
        for(int i=0, reach=0;i<=reach;i++)
        {
            if(i+A[i]>reach) reach=i+A[i];
            if(reach>=n-1) return true;
        }
        return false;
    }
};
