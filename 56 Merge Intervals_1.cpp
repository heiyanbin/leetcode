// 56
// Merge Intervals
// https://leetcode.com//problems/merge-intervals/
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
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) return intervals;
        
        sort(intervals.begin(), intervals.end(),[](Interval a, Interval b) -> bool { return a.start < b.start;});
        vector<Interval> output(1, intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= output.back().end)
                output.back().end = max(output.back().end, intervals[i].end);
            else
                output.push_back(intervals[i]);
        }
        return output;
    }
};