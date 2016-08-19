// 39
// Combination Sum
// https://leetcode.com//problems/combination-sum/
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> x;
        backtrack(0,x,0,candidates,target);
        return output;
    }
    
    void backtrack(int t, vector<int> &x, int start,vector<int> &candidates, int target)
    {
        if(target==0)
            output.push_back(x);
        for(int i=start;i<candidates.size();i++)
        {
            if(candidates[i]>target) return;
            x.push_back(candidates[i]);
            backtrack(t+1, x, i,candidates, target-x[t]);
            x.pop_back();
        }
    }
private:
    vector<vector<int>> output;
};