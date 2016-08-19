// 318
// Maximum Product of Word Lengths
// https://leetcode.com//problems/maximum-product-of-word-lengths/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<int>> index(26, vector<int>(words.size()));
        for (int i = 0; i < words.size(); ++i) {
            for (char c : words[i]) {
                index[c - 'a'][i] = 1;
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                bool noDup = true;
                for (auto &entry : index) {
                    if (entry[i] == 1 && entry[j] == 1) {
                        noDup = false;
                        break;
                    }
                }
                if (noDup) {
                    ans = max(ans, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        
        return ans;
    }


};