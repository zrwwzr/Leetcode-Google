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
        if(intervals.empty()) return vector<Interval>(1, newInterval);
        vector<Interval> res;
        int i;
        for(i = 0; i < intervals.size(); ++i){
            if(intervals[i].start < newInterval.start) 
                res.push_back(intervals[i]);
            else break;
        }
        intervals.insert(intervals.begin() + i, newInterval);
        for(; i < intervals.size(); ++i){
            if(!res.empty() && intervals[i].start <= res.back().end)
                res.back().end = max(res.back().end, intervals[i].end);
            else res.push_back(intervals[i]);
        }
        return res;
    }
};
