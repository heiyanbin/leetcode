// 383
// Ransom Note
// https://leetcode.com//problems/ransom-note/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> count;
        for (char c : magazine) ++count[c];
        
        for (char c : ransomNote) {
            auto it = count.find(c);
            if (it == count.end() || it->second == 0) return false;
            it->second -= 1;
        }
        return true;
    }
};