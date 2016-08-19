// 131
// Palindrome Partitioning
// https://leetcode.com//problems/palindrome-partitioning/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return output;
        DFS(s,0);
        return output;
    }
    void DFS(string &s, int i) {
        if(i == s.size())
            output.push_back(path);
        else {
            for (int k = i; k < s.size(); k++) { //枚举i为起点的palindorme
                if (isPalindrome(s, i, k)) {
                    path.push_back(s.substr(i, k - i + 1));
                    DFS(s, k + 1);
                    path.pop_back();
                }
            }
        }
    }
    bool isPalindrome(string &s, int begin, int end) {
        for (int i = begin, j = end; i < j; i++, j--)
            if(s[i]!=s[j]) return false;
        return true;
    }
private:
    vector<string> path;
    vector<vector<string>> output;
    
};