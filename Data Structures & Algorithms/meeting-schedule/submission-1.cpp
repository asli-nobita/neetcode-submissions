/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();  
        if(n==0) return true; 
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        int st=intervals[0].start,en=intervals[0].end; 
        for(int i=1;i<n;i++) { 
            if(intervals[i].start<en) return false; 
            en=max(en,intervals[i].end); 
        } 
        return true; 
    }
};
