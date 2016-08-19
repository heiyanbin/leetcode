// 164
// Maximum Gap
// https://leetcode.com//problems/maximum-gap/
class Solution {
public:
    int maximumGap(vector<int> nums) {
		if (nums.size() <= 1) return 0;
		int upper = *max_element(nums.begin(), nums.end());
		int lower = *min_element(nums.begin(), nums.end());
		if (lower == upper) return 0;
		vector<int> bucket_min(nums.size(), INT_MAX), bucket_max(nums.size(), INT_MIN);
		for (int e : nums) {
			int index = (double)(e - lower) / (upper - lower) * (nums.size() - 1);
			bucket_min[index] = min(bucket_min[index], e);
			bucket_max[index] = max(bucket_max[index], e);
		}
		int gap = 0, prev = bucket_max[0];
		for (int i = 1; i < nums.size(); ++i) {
			if (bucket_max[i] == INT_MIN) continue;
			gap = max(gap, bucket_min[i] - prev);
			prev = bucket_max[i];
		}
		return gap;
	}
};