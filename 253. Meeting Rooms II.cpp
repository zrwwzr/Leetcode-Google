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
    static bool cmp (const Interval &a, const Interval &b){
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, std::greater<int>> ends;
        int max_room = 0;
        for(int i = 0; i < intervals.size(); ++i){
            while(!ends.empty() && ends.top() <= intervals[i].start)
                ends.pop();
            ends.push(intervals[i].end);
            max_room = max(max_room, (int)ends.size());
        }
        return max_room;
        
    }
};
