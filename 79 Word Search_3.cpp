// 79
// Word Search
// https://leetcode.com//problems/word-search/
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        usedInPath= vector<vector<bool>>(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size() ;j++)
            {
                if(DFS(0,word,i,j,board))
                    return true;
            }
        }
        return false;
    }
    bool DFS(int t, string &word, int i, int j, vector<vector<char> > &board)
    {
        if(t>=word.size())
            return true;
        if(i>=0 && i< board.size() && j>=0 && j<board[0].size() && !usedInPath[i][j] && word[t]==board[i][j]) 
        {
            usedInPath[i][j]=true;
            if(DFS(t+1,word,i,j-1,board))
                return true;
            if(DFS(t+1,word,i,j+1,board))
                return true;
            if(DFS(t+1,word,i-1,j,board))
                return true;
            if(DFS(t+1,word,i+1,j,board))
                return true;
            usedInPath[i][j]=false;
        }
        return false;
    }
private:
    vector<vector<bool>> usedInPath;
};