// 134
// Gas Station
// https://leetcode.com//problems/gas-station/
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
    	if(gas==null || gas.length==0) return -1;
    	int left =0, maxLeft = 0;
    	int start=gas.length-1;
    	for(int i=gas.length-1;i>=0;i--)
    	{
    	    left = left + gas[i]-cost[i] ;
    	    if(left>maxLeft)
    	    {
    	        maxLeft=left;
    	    	start=i;
    	     }
    	}
    	if(left>=0)
    		return start;
    	return -1;
    }
   
}