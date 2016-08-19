// 4
// Median of Two Sorted Arrays
// https://leetcode.com//problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = nums1.size() + nums2.size();
        if (l & 1) return findK(begin(nums1), nums1.size(), begin(nums2), nums2.size(), l / 2 + 1);
        return (findK(begin(nums1), nums1.size(), begin(nums2), nums2.size(), l / 2) + findK(begin(nums1), nums1.size(), begin(nums2), nums2.size(), l / 2 + 1)) / 2.0;
    }
    int findK(vector<int>::iterator A, int m, vector<int>::iterator B, int n, int k) {
        if (m > n) return findK(B, n, A, m, k);
        if (m == 0) return *(B + k - 1);
        if (k == 1) return min(*A, *B);
        int i = min(m, k/2), j = k - i;
        if (*(A + i - 1) == *(B + j - 1)) return *(A + i - 1);
        else if (*(A + i - 1) < *(B + j - 1)) return findK(A + i, min(j, m - i), B, j, j);
        return findK(A, i, B + j, min(i, n - j), i);
    }
};