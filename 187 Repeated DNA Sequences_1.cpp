// 187
// Repeated DNA Sequences
// https://leetcode.com//problems/repeated-dna-sequences/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<int> set;
        unordered_set<string> res;
        hash<string> hash_fn;
        for (int i = 0; i <= (int)s.size() - 10; ++i) {
            string t = s.substr(i, 10);
            if (res.find(t) == res.end()) {
                if (set.find(hash_fn(t)) != set.end()) {
                    res.insert(t);
                    set.erase(hash_fn(t));
                } else 
                    set.insert(hash_fn(t));
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};