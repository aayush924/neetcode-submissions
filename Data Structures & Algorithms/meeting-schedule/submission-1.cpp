/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    return a.end < b.end; // tie-breaker
});
        int start=-1;
        int end=-1;
        for(auto& interval: intervals){
            if(interval.start>start && interval.start<end || interval.end>start && interval.end<end){
                return false;
            }
            start=min(start, interval.start);
            end=max(end, interval.end);
        }
        return true;
    }
};
