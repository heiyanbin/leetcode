// 130
// Surrounded Regions
// https://leetcode.com//problems/surrounded-regions/
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        size_t m= board.size();
        if(m==0) return;
        size_t n=board[0].size();
        if(n==0) return;
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O')
                BFS(0,j,board);
            if(board[m-1][j]=='O')
                BFS(m-1,j,board);
        }
        for(int i=1;i<m-1;i++)
        {
            if(board[i][0]=='O')
                BFS(i,0,board);
            if(board[i][n-1]=='O')
                BFS(i,n-1,board);
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='B')
                    board[i][j]='O';
    }
private:
    void BFS(int i, int j, vector<vector<char>> &board)
    {
        deque<pair<int,int>> q;
        q.push_back(make_pair(i,j));
        board[i][j]='B';
        while(!q.empty())
        {
            int x = q.front().first, y= q.front().second;
            q.pop_front();
            pair<int,int> AJ[4]={{x+1,y},{x-1,y},{x,y+1},{x,y-1}};
            for(auto p : AJ)
                if(p.first>=0 && p.first<board.size() && p.second>=0 && p.second<board[0].size() && board[p.first][p.second]=='O')
                {
                    q.push_back(p);
                    board[p.first][p.second]='B';
                }
        }
    }
};