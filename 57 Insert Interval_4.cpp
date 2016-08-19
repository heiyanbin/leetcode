// 57
// Insert Interval
// https://leetcode.com//problems/insert-interval/
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if(intervals.empty())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        int i=0;
        while(i<intervals.size() && intervals[i].start< newInterval.start)
            i++;
        if(i>=intervals.size())
        {
            if(intervals[i-1].end< newInterval.start)
                intervals.push_back(newInterval);
            else if(newInterval.end>intervals[i-1].end)
                intervals[i-1].end = newInterval.end;
            return intervals;
        }
        int j= i;
        while(j<intervals.size() && intervals[j].end <= newInterval.end)
            j++;
        intervals.erase(intervals.begin()+i,intervals.begin()+j);
        if(intervals.size()==0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        if(i>=intervals.size())
        {
             if(intervals[i-1].end< newInterval.start)
                intervals.push_back(newInterval);
            else if(newInterval.end>intervals[i-1].end)
                intervals[i-1].end = newInterval.end;
            return intervals;
        }
        if(i>0 && newInterval.start<=intervals[i-1].end  &&newInterval.end < intervals[i].start && newInterval.end > intervals[i-1].end)
            intervals[i-1].end = newInterval.end;
        else if(i>0 && newInterval.start<=intervals[i-1].end && newInterval.end>= intervals[i].start)
        {
            intervals[i-1].end = intervals[i].end;
            intervals.erase(intervals.begin()+i);
        }
        else if((i== 0 || newInterval.start>intervals[i-1].end) && newInterval.end < intervals[i].start)
            intervals.insert(intervals.begin()+i, newInterval);
        else if((i==0 || newInterval.start>intervals[i-1].end) && newInterval.end >= intervals[i].start)
            intervals[i].start = newInterval.start;
        return intervals;
    }
};