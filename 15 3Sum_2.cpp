// 15
// 3Sum
// https://leetcode.com//problems/3sum/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        if(num.size()<3) return output;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size()-2;i++)
        {
            if(i!=0 && num[i]==num[i-1])
                continue;
            vector<pair<int,int>> v = twoSum(num,i+1,num.size()-1,-num[i]);
            for(int k=0;k<v.size();k++)
            {
                vector<int> triple;
                triple.push_back(num[i]);
                triple.push_back(num[v[k].first]);
                triple.push_back(num[v[k].second]);
                output.push_back(triple);
            }
        }
        return output;
    }
    vector<pair<int,int>> twoSum(vector<int> &num, int begin, int end, int sum)
    {
        vector<pair<int,int>> v;
        int i= begin, j= end;
        while(i<j)
        {
            if(num[i]+num[j]==sum)
            {
                v.push_back(pair<int,int>(i,j));
                i++; j--;
                while(i<j && num[i]==num[i-1])
                    i++;
                while(i<j && num[j]==num[j+1])
                    j--;
            }
            else if(num[i]+num[j]<sum)
                i++;
            else
                j--;
        }
        return v;
    }
private:
    vector<vector<int>> output;
};