// 264
// Ugly Number II
// https://leetcode.com//problems/ugly-number-ii/
class Solution {
public:
    int nthUglyNumber(int n) {
    	set<long> pq;
    	pq.insert(1);
    	long ans = 1;
    	for (int i = 0; i < n; ++i) {
    		ans = *pq.begin();
    		pq.erase(pq.begin());
    		pq.insert(ans * 2);
    		pq.insert(ans * 3);
    		pq.insert(ans * 5);
    	}
    	return ans;
    }
};