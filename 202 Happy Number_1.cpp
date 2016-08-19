// 202
// Happy Number
// https://leetcode.com//problems/happy-number/
class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        for(int next = 0; true; n = next) {
            for (next = 0; n > 0; next += (n % 10) * (n % 10), n /= 10);
            if (next == 1) return true;
            if (s.find(next) != s.end()) return false;
            s.insert(next);
        }
    }
};