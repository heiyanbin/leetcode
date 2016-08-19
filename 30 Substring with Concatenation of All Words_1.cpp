// 30
// Substring with Concatenation of All Words
// https://leetcode.com//problems/substring-with-concatenation-of-all-words/
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int word_length = L[0].size();
        int cat_length = word_length * L.size();
        vector<int> output;
        unordered_map<string,int> mp;
        for(auto s : L)
            mp[s]++;
        for(int i=0;i<=(int)S.size()-cat_length;i++)
        {
            unordered_map<string,int> dict(mp);
            for(int j=i;j<i+cat_length;j=j+word_length)
            {
                auto it = dict.find(S.substr(j,word_length));
                if(it==dict.end()||it->second==0)
                    break;
                it->second--;
                if(it->second==0) dict.erase(it);
            }
            if(dict.empty()) output.push_back(i);
        }
        return output;
    }
};