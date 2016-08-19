// 39
// Combination Sum
// https://leetcode.com//problems/combination-sum/
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> x;
        backtrack(x,0,candidates,target);
        return output;
    }
    
    void backtrack(vector<int> &x, int start,vector<int> &candidates, int target)
    {
        if(target==0)
            output.push_back(x);
        for(int i=start;i<candidates.size() && candidates[i]<=target;i++)
        {
            x.push_back(candidates[i]);
            backtrack(x, i,candidates, target-candidates[i]);
            x.pop_back();
        }
    }
private:
    vector<vector<int>> output;
};