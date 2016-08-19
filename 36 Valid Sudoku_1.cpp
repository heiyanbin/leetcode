// 36
// Valid Sudoku
// https://leetcode.com//problems/valid-sudoku/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<vector<bool>> row(9, vector<bool>(9, false)), col(9, vector<bool>(9, false));
        vector<vector<vector<bool>>> blo(3, vector<vector<bool>>(3, vector<bool>(9, false)));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int key = board[i][j] - '0' - 1;
                if (row[i][key] || col[j][key] || blo[i / 3][j / 3][key]) return false;
                row[i][key] = true;
                col[j][key] = true;
                blo[i / 3][j / 3][key] = true;
            }
        }
        return true;
    }
};