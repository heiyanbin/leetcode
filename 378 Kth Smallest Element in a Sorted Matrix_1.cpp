// 378
// Kth Smallest Element in a Sorted Matrix
// https://leetcode.com//problems/kth-smallest-element-in-a-sorted-matrix/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        typedef pair<int, pair<int, int>> P;
        
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> marked(n, vector<int>(n, 0));
        
        pq.push({matrix[0][0], {0, 0}});
        marked[0][0] = 1;
        
        for(; pq.size() > 0 ;--k) {
            P p = pq.top(); pq.pop();
            if (k == 1) return p.first;
            
            int i = p.second.first, j = p.second.second;
            if (i + 1 < n && !marked[i + 1][j]) {
                pq.push({matrix[i + 1][j], {i + 1, j}});
                marked[i + 1][j] = 1;
            }
            if (j + 1 < n && !marked[i][j + 1]) {
                pq.push({matrix[i][j + 1], {i, j + 1}});
                marked[i][j + 1] = 1;
            }
        }
        throw invalid_argument("k too big.");
    }
};