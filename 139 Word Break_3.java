// 139
// Word Break
// https://leetcode.com//problems/word-break/
class Solution {
    public boolean wordBreak(String s, Set<String> dict) {
    	if(s==null) return false;
        boolean[] dp = new boolean[s.length()];
        dp[0] = dict.contains(s.substring(0, 1));
        for(int i=1;i<s.length();i++)
        {
        	dp[i] = false;
        	if(dict.contains(s.substring(0, i+1))) 
        	{
        		dp[i] = true;
        		continue;
        	}
        	for (int j=0;j<i;j++)
        	{
        		if(dp[j] && dict.contains(s.substring(j+1,i+1)))
        		{
					dp[i]=true;
					break;  			
        		}
        	}      	
        }
        return dp[s.length()-1];
    }
}