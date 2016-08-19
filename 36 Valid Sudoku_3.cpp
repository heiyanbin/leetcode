// 36
// Valid Sudoku
// https://leetcode.com//problems/valid-sudoku/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i=0;i<board.size();i++)
        {
            vector<int> mp(10,0);
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                    continue;
                int index = board[i][j] - '0';
                if(mp[index])
                    return false;
                else
                    mp[index]++;
            }
        }
        
        for(int j=0;j<board[0].size();j++)
        {
            vector<int> mp(10,0);
            for(int i=0;i<board.size();i++)
            {
                if(board[i][j]=='.')
                    continue;
                int index = board[i][j] - '0';
                if(mp[index])
                    return false;
                else
                    mp[index]++;
            }
        }
        
        for(int i=0;i<9;i=i+3)
        {
            for(int j=0;j<9;j=j+3)
            {
                vector<int> mp(10,0);
                for(int k=0;k<3;k++)
                {
                    for(int m=0;m<3;m++)
                    {
                        if(board[i+k][j+m]=='.')
                            continue;
                        int index = board[i+k][j+m] - '0';
                        if(mp[index])
                            return false;
                        else
                            mp[index]++;
                    }
                }
            }
        }
        return true;
        
    }
};