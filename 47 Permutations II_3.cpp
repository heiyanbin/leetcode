// 47
// Permutations II
// https://leetcode.com//problems/permutations-ii/
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> output;
        permute(0,num,output);
        return output;
    }
    
    void permute(int t,vector<int> &num, vector<vector<int>> &output)
    {
        if(t>=num.size())
            output.push_back(num);
        else
        {
            for(int i=t;i<num.size();i++)
            {
                if (find(num.begin() + t, num.begin() + i, num[i]) != num.begin() + i) continue;
                swap(num[t],num[i]);
                permute(t+1,num, output);
                swap(num[t],num[i]);
            }
        }
    }
};