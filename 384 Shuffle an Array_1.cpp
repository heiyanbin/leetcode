// 384
// Shuffle an Array
// https://leetcode.com//problems/shuffle-an-array/
class Solution {
public:
    Solution(vector<int> nums) {
        a = nums;
        b = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        a = b;
        return a;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < a.size(); ++i) {
            int r = rand() % (i + 1);
            swap(a[r], a[i]);
        }
        return a;
    }
private:
    vector<int> a, b;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */