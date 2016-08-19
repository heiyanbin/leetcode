// 205
// Isomorphic Strings
// https://leetcode.com//problems/isomorphic-strings/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return oneWayCheck(s, t) && oneWayCheck(t, s);
    }
private:
    bool oneWayCheck(string &s, string &t) {
        vector<int> map(256, -1);
        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] < 0) map[s[i]] = t[i];
            else if (map[s[i]] != t[i]) return false;
        }
        return true;
    }
};