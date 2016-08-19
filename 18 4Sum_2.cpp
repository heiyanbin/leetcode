// 18
// 4Sum
// https://leetcode.com//problems/4sum/
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> output;
        int n = num.size();
        if(n<4) return output;
        sort(num.begin(),num.end());
        unordered_map<int,vector<pair<int,int>>> map;
        for(int i=0;i<n-3;i++)
        {
            if(i!=0 && num[i]==num[i-1])
                continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j!=i+1 && num[j]==num[j-1])
                    continue;
                map[num[i]+num[j]].push_back(pair<int,int>(i,j));
            }
        }
        for(int i=2;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(j!=i+1 && num[j]==num[j-1])
                    continue;
                int x = target-num[i]-num[j];
                if(map.find(x)==map.end())
                    continue;
                for(auto it= map[x].begin();it<map[x].end();it++)
                {
                    if((*it).second<i)
                    {
                        int a[]={num[(*it).first],num[(*it).second],num[i],num[j]};
                        output.push_back(vector<int>(a,a+4));
                    }
                }
            }
        }
        sort(output.begin(),output.end());
        output.erase(unique(output.begin(),output.end()),output.end());
        return output;
    }
};