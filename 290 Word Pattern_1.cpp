// 290
// Word Pattern
// https://leetcode.com//problems/word-pattern/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
    	map<char, string> patternTable;
    	set<string> used;
    	int i = 0, j = 0;
    	for (int start = -1; i <= str.size() && j < pattern.size(); ++i) {
    		if (i < str.size() && str[i] != ' ') {
    			if (i == 0 || str[i - 1] == ' ') start = i;
    		}
    		else if (i > 0 && str[i - 1] != ' ') {
    			string word = str.substr(start, i - start);
    			auto it = patternTable.find(pattern[j]);
    			if (it != patternTable.end()) {
    				if (it->second != word) return false;
    				else ++j;
    			}
    			else if (used.find(word) == used.end()) {
    				patternTable[pattern[j++]] = word;
    				used.insert(word);
    			}
    			else 
    				return false;
    		}
    	}
    	return j == pattern.size() && i == str.size() + 1;
    }
};