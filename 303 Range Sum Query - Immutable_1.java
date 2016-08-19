// 303
// Range Sum Query - Immutable
// https://leetcode.com//problems/range-sum-query-immutable/
public class NumArray {

    public NumArray(int[] nums) {
        prefixSum = new int[nums.length];
        for (int i = 0; i < nums.length; ++i)
            prefixSum[i] = (i == 0 ? 0 : prefixSum[i - 1]) + nums[i];
    }

    public int sumRange(int i, int j) {
        return prefixSum[j] - (i == 0 ? 0 : prefixSum[i - 1]);
    }
    
    private int[] prefixSum;
}


// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);