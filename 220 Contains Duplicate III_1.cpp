// 220
// Contains Duplicate III
// https://leetcode.com//problems/contains-duplicate-iii/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		multiset<int> tree;
		for (int i = 0; i < nums.size(); ++i) {
			auto it = tree.lower_bound(nums[i] - t);
			if (it != tree.end() && *it <= (long long)nums[i] + t) return true;
			tree.insert(nums[i]);
			if (i - k >= 0) tree.erase(tree.find(nums[i - k]));
		}
		return false;
	}
};