// 349
// Intersection of Two Arrays
// https://leetcode.com//problems/intersection-of-two-arrays/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        vector<int> res;
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size(); ) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                for (++i; i < nums1.size() && nums1[i - 1] == nums1[i]; ++i);
                for (++j; j < nums2.size() && nums2[j - 1] == nums2[j]; ++j);
            }
            else if (nums1[i] < nums2[j]) ++i;
            else ++j;
        }
        return res;
    }
};