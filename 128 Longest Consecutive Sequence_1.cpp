// 128
// Longest Consecutive Sequence
// https://leetcode.com//problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int,bool> used;
        for(auto &e :num) used[e]=false;
        int maxLen =1;
        for(auto &e : used) {
            if(e.second) continue;
            int len=1;
            for(int x = e.first-1;used.find(x)!=used.end();--x){
                len++;
                used[x]=true;
            }
            for(int x = e.first+1;used.find(x)!=used.end();++x){
                len++;
                used[x]=true;
            }
            maxLen = max(maxLen,len);
        }
        return maxLen;
    }
};