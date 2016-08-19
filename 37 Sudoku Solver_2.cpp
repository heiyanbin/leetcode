// 37
// Sudoku Solver
// https://leetcode.com//problems/sudoku-solver/
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		this->row = vector<vector<int>> (9, vector<int>(9));
		this->col = vector<vector<int>>(9, vector<int>(9));
		this->blo = vector<vector<vector<int>>>(3, vector<vector<int>>(3, vector<int>(9)));
		vector<pair<int, int>> blank;
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j)
			    if (board[i][j] == '.')
				    blank.push_back(make_pair(i, j));
				else
				    mark(i, j, board[i][j] - '0', 1);
		}
		dfs (board, blank, 0);
	}
	
private:
    bool dfs(vector<vector<char>> & board, vector<pair<int, int>> &blank, int t) {
	    if (t == blank.size()) return true;
        int i = blank[t].first, j = blank[t].second;
		for (int k = 1; k <= 9; ++k) {
			if (row[i][k - 1] || col[j][k - 1] || blo[i / 3][j / 3][k - 1]) continue;
			board[i][j] = k + '0';
			mark(i, j, k, 1);
			if (dfs(board, blank, t + 1)) return true;
			mark(i, j, k, 0);
		}
		return false;
	}
	void mark(int i, int j, int k, int flag) {
	    row[i][k - 1] = flag;
		col[j][k - 1] = flag;
		blo[i / 3][j / 3][k - 1] = flag;
	}
	vector<vector<int>> row;
	vector<vector<int>> col;
	vector<vector<vector<int>>> blo;
};