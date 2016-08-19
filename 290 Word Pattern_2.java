// 290
// Word Pattern
// https://leetcode.com//problems/word-pattern/
public class Solution {
    public boolean wordPattern(String pattern, String str) {
    	if (pattern == null || str == null) return false;
    	String[] words = str.split("\\s+");
    	Map<Character, String> map = new HashMap<Character, String>();
    	Set<String> set = new HashSet<String>();
    	int i = 0;
    	for (int j = 0; j < pattern.length(); ++j) {   
    		if (i == words.length) return false;
    		char p = pattern.charAt(j);
    		if (map.containsKey(p)) {
    			if (!map.get(p).equals(words[i])) return false;
    			else ++i;
    		}
    		else {
    			if (set.contains(words[i])) return false;
    			else {
    				map.put(p, words[i]);
    				set.add(words[i]);
    				++i;
    			}
    		}
    	}
    	return i == words.length;
    }
}