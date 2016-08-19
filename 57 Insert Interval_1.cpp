// 57
// Insert Interval
// https://leetcode.com//problems/insert-interval/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i = 0;
        vector<Interval> res;
        while (i < intervals.size() && newInterval.start > intervals[i].end) {
            res.push_back(intervals[i]);
            i++;
        }
        for (; i < intervals.size() && newInterval.end >= intervals[i].start; i++) {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }
        res.push_back(newInterval);
        for (; i < intervals.size(); i++) 
            res.push_back(intervals[i]);
        return res;
        
    }
};