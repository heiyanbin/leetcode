// 198
// House Robber
// https://leetcode.com//problems/house-robber/
class Solution {
public:
    int rob(vector<int> &num) {
        if (num.empty()) return 0;
        int maxMoney1 = num[0];
        int maxMoney2 = 0;
        int res = num[0];
        for (int i = 1; i < num.size(); ++i) {
            res = max(res, maxMoney2 + num[i]);
            int temp = maxMoney1;
            maxMoney1 = max(maxMoney2 + num[i], maxMoney1);
            maxMoney2 = temp;
        }
        return res;
    }
};