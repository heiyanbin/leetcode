// 134
// Gas Station
// https://leetcode.com//problems/gas-station/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start =0, sum = 0, total=0;
        for(int i=0;i<gas.size();i++)
        {
            total+=gas[i]-cost[i];
            sum  +=gas[i]-cost[i];
            if(sum<0)
            {
                start = i+1;
                sum=0;
            }
        }
        return total>=0? start : -1;
    }
};