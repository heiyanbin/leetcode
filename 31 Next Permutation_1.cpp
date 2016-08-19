// 31
// Next Permutation
// https://leetcode.com//problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
    	if (nums.size() <= 1) return;
    	
    	//find the  position closest to the right end, where we could find a bigger number to the right
    	int i = nums.size() - 2;
    	for (; i >= 0 && nums[i] >= nums[i + 1]; --i) ;
    	
    	if (i < 0) reverse(nums.begin(),nums.end()); //alreay the biggest, reset
    	else {
    		int j = nums.size() - 1;
    		for (; j > i && nums[j] <= nums[i]; --j);
    		swap(nums[i], nums[j]);
    		reverse(begin(nums) + i + 1, end(nums));
    	}
    }
};