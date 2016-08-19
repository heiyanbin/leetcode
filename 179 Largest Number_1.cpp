// 179
// Largest Number
// https://leetcode.com//problems/largest-number/
class Solution {
public:
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), [](int a, int b)->bool{ return to_string(a) + to_string(b) > to_string(b) + to_string(a);});
        string res;
        bool isZero = true;
        for (int e : num) {
            res.append(to_string(e));
            if (e != 0) isZero = false;
        }
        return isZero ? "0" : res;
    }
};