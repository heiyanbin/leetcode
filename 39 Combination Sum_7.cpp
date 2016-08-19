// 39
// Combination Sum
// https://leetcode.com//problems/combination-sum/
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> x;
        backtrack(0,x,candidates,target);
        return output;
    }
    
    void backtrack(int t, vector<int> &x, vector<int> &candidates, int target)
    {
        for(int i=0;i<candidates.size();i++)
        {
            if(t>0 && candidates[i]<x[t-1]) continue;
            if(x.size()==t)
                x.push_back(candidates[i]);
            else
                x[t] = candidates[i];
            if(x[t]==target)
                output.push_back(vector<int>(x.begin(),x.begin()+t+1));
            else if(x[t]<target)
                backtrack(t+1, x, candidates, target-x[t]);
        }
    }
private:
    vector<vector<int>> output;
};