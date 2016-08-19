// 140
// Word Break II
// https://leetcode.com//problems/word-break-ii/
class Solution {
    public List<String> wordBreak(String s, Set<String> dict) { 	
    	List<String> output = new ArrayList<String>();
    	
    	Set<Character> charSet =  new HashSet<Character>();
    	for(String word : dict)
    	{
    		for(int i=0;i<word.length();i++)
    		{
    			charSet.add(word.charAt(i));
    		}
    	}
    	for(int i=0;i<s.length();i++)
    	{
    		if(!charSet.contains(s.charAt(i)))
    			return output;
    	}
    	select (s, "", dict, output);
        return output;
    }
    void select(String s, String x, Set<String> dict, List<String> output)
    {
    	if(s==null||s.length() ==0 )
    	{
    		output.add(x.trim());
    		return;
    	}
    	for(int i=1;i<=s.length();i++)
    	{
    		String prefix = s.substring(0, i);
    		if(dict.contains(prefix))
    		{
    			select(s.substring(i), x+prefix+' ', dict, output);
    		}  		
    	}
    }
}