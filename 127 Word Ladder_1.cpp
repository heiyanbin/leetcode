// 127
// Word Ladder
// https://leetcode.com//problems/word-ladder/
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end) return 0;
        queue<string> q;
        unordered_map<string, int> d;
        for (q.push(start), d[start] = 1; !q.empty(); q.pop()) {
            string word = q.front();
            auto next = word;
            for (int i = 0; i < word.size(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    next[i] = c;
                    if (dict.find(next) != dict.end() && d.find(next) == d.end()) {
                        d[next] = d[word] + 1;
                        if (next == end) return d[next];
                        q.push(next);
                    }
                }
                next[i] = word[i];
            }
        }
        return 0;
    }
};