// 1
// Two Sum
// https://leetcode.com//problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> m;
        for(int i=0;i<numbers.size();i++)
        {
            if(m.find(target-numbers[i])!=m.end())
                return vector<int>{m[target-numbers[i]]+1,i+1};
            else
                m[numbers[i]]=i;
        }
        return vector<int>();
    }
};