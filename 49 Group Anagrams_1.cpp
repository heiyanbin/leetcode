// 49
// Group Anagrams
// https://leetcode.com//problems/anagrams/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> groups;
        for(auto s : strs)
        {
            string key=s;
            sort(key.begin(),key.end());
            groups[key].push_back(s);
        }
        vector<string> output;
        for(auto it=groups.cbegin();it!=groups.cend();it++)
            if(it->second.size()>1)
                output.insert(output.end(),it->second.begin(),it->second.end());
        return output;
    }
};