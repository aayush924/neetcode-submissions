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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size()==0) return 0;
        
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            if(a.start==b.start){
                return a.end<b.end;
            }
            else return a.start<b.start;
        });

        vector<int> rooms;
        bool scheduled=false;
        rooms.push_back(intervals[0].end);
        for(int i=1;i<intervals.size();i++){
            scheduled=false;
            Interval curr=intervals[i];
            for(int j=0;j<rooms.size();j++){
                if(curr.start>=rooms[j]){
                    rooms[j]=curr.end;
                    scheduled=true;
                    break;
                }
            }
            if(!scheduled) rooms.push_back(curr.end);
        }
        return rooms.size();
    }
};
