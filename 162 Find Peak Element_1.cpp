// 162
// Find Peak Element
// https://leetcode.com//problems/find-peak-element/
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int l = 0, r = num.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (num[mid] > num[mid + 1]) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};