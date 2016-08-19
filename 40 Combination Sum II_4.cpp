// 40
// Combination Sum II
// https://leetcode.com//problems/combination-sum-ii/
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        if(num.empty()) 
            return output;
        vector<int> x(num.size());
        sort(num.begin(),num.end());
        backtrack(0,x,0,num,target);
        return output;
    }
    void backtrack(int t, vector<int> &x, int start, vector<int> &num, int target)
    {
        for(int i=start;i<num.size();i++)
        {
            bool skip = false;
            for(int j=start;j<i;j++)
            {
                if(num[j]==num[i])
                {
                    skip = true;
                    break;
                }
            }
            if(skip) 
                continue;

            x[t]=num[i];
            if(x[t]==target)
                output.push_back(vector<int>(x.begin(),x.begin()+t+1));
            else if(x[t]<target)
                backtrack(t+1,x,i+1,num,target-x[t]);
        }
    }
private:
    vector<vector<int>> output;
};