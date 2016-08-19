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
        vector<Interval> output;
        sort(intervals.begin(),intervals.end(),Solution::compare);
        for(auto i : intervals)
        {
            while(!output.empty() && i.start<=output.back().start)
                output.pop_back();
            if(output.empty() || i.start>output.back().end)
                output.push_back(i);
            else if(i.start<= output.back().end)
                output.back().end= i.end;
        }
        return output;
    }
    static bool compare(Interval a, Interval b)
    {
        return a.end <b.end;
    }
};