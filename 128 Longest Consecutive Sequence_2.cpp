// 128
// Longest Consecutive Sequence
// https://leetcode.com//problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int,bool> mp;
        for(int x : num)
            mp[x]=false;
        int maxLen = 0;
        for(auto e: mp)
        {
            if(mp[e.first]==true) 
                continue;
            int i=1,upper, lower;
            while(mp.count(e.first+i)>0)
            {
                mp[e.first+i]=true;
                i++;
            }
            upper = i-1;
            i=1;
            while(mp.count(e.first-i)>0)
            {
                mp[e.first-i]=true;
                i--;
            }
            lower = i-1;
            if(upper-lower+1>maxLen)
                maxLen = upper-lower +1;
        }
        return maxLen;
    }
};