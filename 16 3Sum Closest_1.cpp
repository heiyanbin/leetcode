// 16
// 3Sum Closest
// https://leetcode.com//problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        assert(num.size()>=3);
        sort(num.begin(),num.end());
        int minDiff = INT_MAX;
        int closestSum =INT_MIN;
        for(int i=0;i<num.size()-2;i++)
        {
            if(i!=0 && num[i]==num[i-1])
                continue;
            pair<int,int> p = twoSumClosest(num,i+1,num.size()-1,target-num[i]);
            int sum = num[i] +  num[p.first] + num[p.second];
            if(sum == target) 
                return target;
            if(abs(sum -target)<minDiff)
            {
                closestSum= sum;
                minDiff = abs(sum -target);
            }
        }
        return closestSum;
    }
    pair<int,int> twoSumClosest(vector<int> &num, int begin, int end, int sum)
    {
        int i= begin, j= end;
        int minDiff =INT_MAX;
        pair<int,int> minPair;
        int diff;
        while(i<j)
        {
            int x = num[i]+num[j];
            diff= abs(sum-x);
            if(diff<minDiff)
            {
                minDiff = diff;
                minPair = pair<int,int>(i,j);
            }
            if(x==sum)
            {
                return minPair;
            }            
            else if(x<sum)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return minPair;
    }
};