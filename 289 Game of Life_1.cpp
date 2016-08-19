// 289
// Game of Life
// https://leetcode.com//problems/game-of-life/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        queue<int> q;
        int k = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                int count = 0;
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (i + di < 0 || i + di >= board.size() || j + dj < 0 || j + dj >= board[i].size() || (di == 0 and dj == 0)) continue;
                        if (board[i + di][j + dj] == 1) ++count;
                    }
                }
                if (board[i][j] == 0) q.push(count == 3 ? 1 : 0);
                else if (count < 2 || count > 3) q.push(0);
                else q.push(1);
                if (q.size() > board[0].size() + 1) {
                    board[k / board[0].size()][k % board[0].size()] = q.front();
                    q.pop(), ++k;
                }
            }
        }
        while (!q.empty()) {
            board[k / board[0].size()][k % board[0].size()] = q.front();
            q.pop(), ++k;
        }
    }
};