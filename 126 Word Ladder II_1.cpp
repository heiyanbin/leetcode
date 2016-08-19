// 126
// Word Ladder II
// https://leetcode.com//problems/word-ladder-ii/
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        queue<string> q;
        q.push(start);
        unordered_set<string> levelVisited, visited;
        visited.insert(start);
        unordered_map<string,vector<string>> prev;
        bool found = false;
        while(!q.empty() && !found) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i ++) {
                string word = q.front(); q.pop();
                if (word == end) {
                    found = true;
                    break;
                }
                string next = word;
                for (int k = 0; k < word.size(); k ++) {
                    for (char l ='a'; l <='z'; l ++) {
                        if (l == word[k]) continue;
                        next[k] = l;
                        if (visited.find(next) == visited.end() && dict.find(next) != dict.end()) {
                            levelVisited.insert(next);
                            prev[next].push_back(word);
                        }
                        if (next == end) break;
                    }
                    next[k] = word[k];
                }
            }
            for (auto &e : levelVisited) {
                visited.insert(e);
                q.push(e);
            }
            levelVisited.clear();
        }
        vector<vector<string>> res;
        vector<string> path;
        get_path(end, start, path, prev, res);
        return res;
    }
    void get_path(string &s, string &end, vector<string> &path, unordered_map<string,vector<string>> &prev, vector<vector<string>> &res) {
        path.push_back(s);
        if (s == end)
            res.push_back(vector<string>(path.rbegin(), path.rend()));
        else
            for(auto &word : prev[s])
                get_path(word, end, path, prev, res);
        path.pop_back();
    }
};