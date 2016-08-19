// 215
// Kth Largest Element in an Array
// https://leetcode.com//problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int m = partition(nums, i, j);
            if (m == k - 1) return nums[m];
            if (m < k - 1) i = m + 1;
            else j = m - 1;
        }
    }
    int partition(vector<int> &A, int l, int r) {
        int i = l;
        for (int j = l + 1; j <=r; j++)
            if (A[j] > A[l]) swap(A[++i], A[j]);
        swap(A[i], A[l]);
        return i;
    }
};