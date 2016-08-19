// 18
// 4Sum
// https://leetcode.com//problems/4sum/
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> output;
        if(num.size()<4) return output;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size()-3;i++)
        {
            if(i!=0 && num[i]==num[i-1])
                continue;
            for(int j=i+1;j<num.size()-2;j++)
            {
                if(j!=i+1 && num[j]==num[j-1])
                    continue;
                int begin = j+1, end = num.size()-1;
                while(begin<end)
                {
                    int sum = num[i]+num[j]+num[begin]+num[end];
                    if(sum==target)
                    {
                        vector<int> v;
                        v.push_back(num[i]);
                        v.push_back(num[j]);
                        v.push_back(num[begin]);
                        v.push_back(num[end]);
                        output.push_back(v);
                        begin++; end--;
                        while(begin<end && num[begin]==num[begin-1])
                            begin++;
                        while(begin<end && num[end]==num[end+1])
                            end--;
                    }
                    else if(sum < target)
                        begin++;
                    else
                        end--;
                }
            }
        }
        return output;
    }
};