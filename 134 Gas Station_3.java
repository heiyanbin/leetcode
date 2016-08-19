// 134
// Gas Station
// https://leetcode.com//problems/gas-station/
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
    	if(gas==null || gas.length==0) return -1;
    	int surplus = 0, curMaxSurplus =0;
    	int station=0;
    	for(int i=0;i<gas.length;i++)
    	{
    		surplus += gas[i]-cost[i];
    		if(curMaxSurplus>0)   			
    			curMaxSurplus += gas[i]-cost[i];   		
    		else
    		{
    			curMaxSurplus = gas[i] -cost[i];
    			station = i;
    		}    	
    	}
    	if(surplus>=0)
    		return station;
    	return -1;
    }
}