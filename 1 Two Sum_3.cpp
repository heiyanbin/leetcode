// 1
// Two Sum
// https://leetcode.com//problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> m;
        vector<int> v;
        for(int i=0;i<numbers.size();i++)
        {
            if(m.count(target-numbers[i])>0)
            {
                v.push_back(m[target-numbers[i]]+1);
                v.push_back(i+1);
                break;
            }
            else
            {
                m[numbers[i]]=i;
            }
        }
        return v;
    }
};