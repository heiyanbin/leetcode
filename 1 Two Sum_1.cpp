// 1
// Two Sum
// https://leetcode.com//problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < numbers.size(); i++) {
            auto it = m.find(target - numbers[i]);
            if (it != m.end())
                return vector<int> {it -> second + 1, i + 1};
            else
                m [ numbers [i] ] = i;
        }
        return vector<int>();
    }
};