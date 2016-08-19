// 76
// Minimum Window Substring
// https://leetcode.com//problems/minimum-window-substring/
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> table(256, 0), count(256, 0);
        for (char c : t) table[c]++;
        int i = 0, num = 0, minLen = s.size() + 1, minStart = -1;
        for (int j = 0; j < s.size(); j++) {
            if (table[s[j]] == 0) continue;
            if (count[s[j]] < table[s[j]]) num++;
            count[s[j]]++;
            for (; num == t.size(); i++) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    minStart = i;
                }
                count[s[i]]--;
                if (table[s[i]] > 0 && count[s[i]] < table[s[i]]) num--;
            }
        }
        return minStart >= 0 ? s.substr(minStart, minLen) : "";
    }
};