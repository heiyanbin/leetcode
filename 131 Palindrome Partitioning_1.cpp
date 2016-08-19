// 131
// Palindrome Partitioning
// https://leetcode.com//problems/palindrome-partitioning/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return output;
        auto isPal = calcPal(s);
        DFS(s, 0, isPal);
        return output;
    }
    void DFS(string &s, int i, vector<vector<bool>> &isPal) {
        if(i == s.size())
            output.push_back(path);
        else {
            for (int j = i; j < s.size(); j++) { //枚举i为起点的palindorme
                if (isPal[i][j]) {
                    path.push_back(s.substr(i, j - i + 1));
                    DFS(s, j + 1, isPal);
                    path.pop_back();
                }
            }
        }
    }
    vector<vector<bool>> calcPal(string &s) {
        vector<vector<bool>> pal(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; --i)
            for (int j = i; j < s.size(); ++j)
                if (s[i] == s[j] && (j - i < 2 || pal[i+1][j-1]))
                    pal[i][j] = true;
        return pal;
    }
private:
    vector<string> path;
    vector<vector<string>> output;
};