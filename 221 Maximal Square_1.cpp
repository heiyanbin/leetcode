// 221
// Maximal Square
// https://leetcode.com//problems/maximal-square/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
		int m = matrix.size(), n = matrix[0].size(), len = INT_MIN;
		vector<int> f(n);
		for (int i = 0; i < m; ++i) {
			for (int j = 0, left_up; j < n;  ++j) {
				int new_left_up = f[j];
				if (j == 0) 
					f[j] = matrix[i][0] - '0';
				else 
					f[j] = matrix[i][j] == '0' ? 0 : min(min(f[j - 1], f[j]), left_up) + 1;	
				len = max(len, f[j]);	
				left_up = new_left_up;
			}
		}
		return len * len;
    }
};