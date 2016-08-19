// 372
// Super Pow
// https://leetcode.com//problems/super-pow/
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int cur = 1, x = a % 1337;
        for (int i = b.size() - 1; i >= 0; --i) {
            for (int k = 0; k < b[i]; ++k) {
                cur = cur * x % 1337;
            }
            
            int y = 1;
            for (int k = 0; k < 10; ++k) {
                y = y * x % 1337;
            }
            x = y;
        }
        
        return cur;
    }
};