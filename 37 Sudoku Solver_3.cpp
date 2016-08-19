// 37
// Sudoku Solver
// https://leetcode.com//problems/sudoku-solver/
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        vector<unordered_set<char>> rowMap(9);
        vector<unordered_set<char>> colMap(9);
        vector<unordered_set<char>> boxMap(9);
        vector<pair<int,int>> blank;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    blank.push_back(pair<int,int>(i,j));
                    continue;
                }
                rowMap[i].insert(board[i][j]);
            }
        }
        for(int j=0;j<9;j++)
        {
            for(int i=0;i<9;i++)
            {
                if(board[i][j]=='.')
                    continue;
                colMap[j].insert(board[i][j]);
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
                        boxMap[(i/3) * 3 +j/3].insert(board[i+k][j+m]);
                    }
                }
            }
        }
        found = false;
        DFS(0,blank,rowMap,colMap,boxMap,board);
        
    }
    
    void DFS(int t, vector<pair<int,int>> &blank,  vector<unordered_set<char>> &rowMap,  vector<unordered_set<char>> &colMap,  vector<unordered_set<char>> &boxMap, vector<vector<char> > &board)
    {
        if(t>=blank.size())
        {
            found = true;
        }
        else
        {
            int i= blank[t].first;
            int j= blank[t].second;
            for(char digit ='1';digit<='9';digit++)
            {
                if(rowMap[i].count(digit)>0 || colMap[j].count(digit)>0 || boxMap[i/3 * 3 + j/3].count(digit)>0)
                {
                    continue;
                }
                board[i][j]=digit;
                rowMap[i].insert(digit);
                colMap[j].insert(digit);
                boxMap[i/3*3+j/3].insert(digit);
                DFS(t+1,blank,rowMap,colMap,boxMap,board);
                rowMap[i].erase(digit);
                colMap[j].erase(digit);
                boxMap[i/3*3+j/3].erase(digit);
                if(found)
                    return;
            }
        }
    }
private:
    bool found;
    
};