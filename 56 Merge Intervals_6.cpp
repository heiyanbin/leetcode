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
        if(intervals.empty()) return output;
        sort(intervals.begin(),intervals.end(),Solution::compare);
        output.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            while(!output.empty() && intervals[i].start<=output.back().start)
                output.pop_back();
            if(output.empty() || intervals[i].start>output.back().end)
                output.push_back(intervals[i]);
            else if(intervals[i].start<= output.back().end)
            {
                output.back().end= intervals[i].end;
            }
        }
        return output;
    }
    static bool compare(Interval a, Interval b)
    {
        return a.end <b.end;
    }
};