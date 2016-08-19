// 223
// Rectangle Area
// https://leetcode.com//problems/rectangle-area/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A, E), right = min(C, G);
        int top = min(D, H), bottom = max(B, F);
        int overlap = left < right && bottom < top ? (right - left) * (top - bottom) : 0;
        return (C - A) * (D - B) + (G - E) * (H - F) - overlap;
    }
};