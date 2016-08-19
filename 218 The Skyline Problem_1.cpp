// 218
// The Skyline Problem
// https://leetcode.com//problems/the-skyline-problem/
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        return getSkyline(buildings, 0, buildings.size() - 1);
    }
private:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &b, int l, int r) {
        if (l == r) return {{b[l][0], b[l][2]}, {b[l][1], 0}};
        int m = l + (r - l) / 2;
        return merge(getSkyline(b, l, m), getSkyline(b, m + 1, r));
    }
    
    vector<pair<int, int>> merge(vector<pair<int, int>> &&a, vector<pair<int, int>> &&b) {
        vector<pair<int, int>> ans;
        for (int i = 0, j = 0, leftH = 0, rightH = 0; i < a.size() || j < b.size();) {
            if (i == a.size()) ans.push_back(b[j++]);
            else if (j == b.size()) ans.push_back(a[i++]);
            else {
                pair<int, int> cur;
                if (a[i].first < b[j].first) {
                    cur.first = a[i].first;
                    leftH = a[i++].second;
                }
                else if (a[i].first > b[j].first) {
                    cur.first = b[j].first;
                    rightH = b[j++].second;
                }
                else {
                    cur.first = a[i].first;
                    leftH = a[i++].second;
                    rightH = b[j++].second;
                }
                cur.second = max(leftH, rightH);
                if (ans.empty() || cur.second != ans.back().second) ans.push_back(cur);
            }
        }
        return ans;
    }
};