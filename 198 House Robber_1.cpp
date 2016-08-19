// 198
// House Robber
// https://leetcode.com//problems/house-robber/
class Solution {
public:
    int rob(vector<int> &num) {
        if (num.empty()) return 0;
        int a = 0, b = num[0];
        for (int i = 1; i < num.size(); ++i) {
            int c = max(a + num[i], b);
            a = b;
            b = c;
        }
        return b;
    }
};