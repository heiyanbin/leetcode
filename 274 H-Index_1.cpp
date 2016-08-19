// 274
// H-Index
// https://leetcode.com//problems/h-index/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(begin(citations), end(citations));
        int ans = 0;
        for (int h = 1; h <= citations.size(); ++h) {
            int smaller = lower_bound(begin(citations), end(citations), h) - begin(citations);
            int equalAndSmaller = upper_bound(begin(citations), end(citations), h) - begin(citations);
            int greater = citations.size() - equalAndSmaller, equal = equalAndSmaller - smaller;
            if (greater <= h && equal >= (h - greater)) ans = h;
        }
        return ans;
    }
};