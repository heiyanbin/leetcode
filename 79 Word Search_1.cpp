// 79
// Word Search
// https://leetcode.com//problems/word-search/
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        usedInPath= vector<vector<bool>>(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size() ;j++) {
                if (DFS(0, word, i, j, board))
                    return true;
            }
        }
        return false;
    }
private:
    bool DFS(int t, string &word, int i, int j, vector<vector<char> > &board) {
        if (t == word.size()) return true;
        if(i < 0 || i == board.size() || j < 0 || j == board[i].size() || usedInPath[i][j] || word[t] != board[i][j]) return false;
        usedInPath[i][j]=true;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for (auto &d : directions) {
            if (DFS(t + 1, word, i + d.first, j + d.second, board)) return true;
        }
        usedInPath[i][j]=false;
        return false;
    }
    vector<vector<bool>> usedInPath;
};