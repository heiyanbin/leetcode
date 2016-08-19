// 352
// Data Stream as Disjoint Intervals
// https://leetcode.com//problems/data-stream-as-disjoint-intervals/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto it = right.lower_bound(val);
        if (it != right.end() && it->second.start <= val) return;
        
        auto cur = Interval(val, val);
        left[val] = cur;
        right[val] =cur;
        
        it = right.find(val - 1);
        if (it != right.end()) {
            left.erase(cur.start);
            right.erase(cur.end);
            
            cur.start = it->second.start;
            
            right.erase(val - 1);
            left.erase(cur.start);
            
            left[cur.start] = cur;
            right[cur.end] = cur;
        }
        
        it = left.find(val + 1);
        if (it != left.end()) {
            left.erase(cur.start);
            right.erase(cur.end);
            
            cur.end = it->second.end;
            
            left.erase(val + 1);
            right.erase(cur.end);
            
            left[cur.start] = cur;
            right[cur.end] = cur;
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> ans;
        for (auto &i : left) {
            ans.push_back(i.second);
        }
        return ans;
    }
private:
    map<int, Interval> left, right;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */