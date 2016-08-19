// 46
// Permutations
// https://leetcode.com//problems/permutations/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> output;
        vector<int> x;
        permute(x, num, output);
        return output;
    }
    
    void permute(vector<int> &x, vector<int> &num, vector<vector<int>> &output)
    {
        if(x.size()==num.size())
            output.push_back(x);
        else
        {
            for(int i=0;i<num.size();i++)
            {
                if(find(x.begin(),x.end(),num[i])==x.end())
                {
                    x.push_back(num[i]);
                    permute(x,num,output);
                    x.pop_back();
                }
            }
        }
    }
};