// 264
// Ugly Number II
// https://leetcode.com//problems/ugly-number-ii/
class Solution {
public:
    int nthUglyNumber(int n) {
    	if (n <= 0) return 0;
    	int f[] = {2, 3, 5}, t[] = {0, 0, 0};
    	vector<int> A = {1, 2, 3, 4, 5};
    	if (n <= 5) return A[n - 1];
    	while (A.size() < n ) {
    		int next = INT_MAX;
    		for (int i = 0; i < 3; ++i) {
    			for (int j = t[i]; j < A.size(); ++j) {
    				if (f[i] * A[j] > A.back()) {
    					next = min(next, f[i] * A[j]);
    					t[i] = j;
    					break;
    				}
    			}
    		}
    		A.push_back(next);
    	}
	    return A.back();
    }
};