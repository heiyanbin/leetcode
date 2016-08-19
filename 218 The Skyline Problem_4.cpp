// 218
// The Skyline Problem
// https://leetcode.com//problems/the-skyline-problem/
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> sides;
        for (auto &b : buildings) {
            sides.push_back({b[0], 0, b[2]});
            sides.push_back({b[1], 1, b[2]});
        }
        sort(sides.begin(), sides.end());
        multiset<int> s;
        int curX = 0;
        vector<pair<int, int>> res;
        for (auto &side : sides) {
            if (s.empty()) curX = side[0];
            else {
                auto maxH = *s.rbegin();
                if (side[0] > curX && (side[2] > maxH || side[2] == maxH && side[1] == 1 && s.count(side[2]) == 1)) {
                    res.push_back(make_pair(curX, maxH));
                    curX = side[0];
                }
            }
            if (side[1] == 0) s.insert(side[2]);
            else {
                s.erase(s.find(side[2]));
                if (s.empty()) res.push_back(make_pair(curX, 0));
            }
        }
        return res;
    }
};