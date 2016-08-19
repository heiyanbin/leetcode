// 4
// Median of Two Sorted Arrays
// https://leetcode.com//problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total & 1) return findK(A, m, B, n, total / 2 + 1);
        else return (findK(A, m, B, n, total / 2) + findK(A, m, B, n, total / 2 + 1)) / 2.0;
    }
    
    int findK(int A[], int m, int B[], int n, int k) {
        if (m > n) return findK(B, n, A, m, k);
        if (m == 0) return B[k-1];
        if (k == 1) return min(A[0], B[0]);
        int i = min(k / 2, m), j = k-i;
        if (A[i - 1] < B[j - 1]) return findK(A + i, m - i, B, j, j);
        else if(A[i - 1] > B[j - 1]) return findK(A, i, B + j, n - j, i);
        return A[i-1];
    }
};