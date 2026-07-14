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
        int n=intervals.size(); 
        if(n==0) return 0; 
        vector<int> start,end; 

        for(auto it:intervals) {
            start.push_back(it.start); 
            end.push_back(it.end); 
        } 
        sort(start.begin(),start.end()); 
        sort(end.begin(),end.end()); 

        int res=0,count=0; 
        int st=0,en=0; 
        while(st<n) { 
            if(start[st]<end[en]) { 
                st++; 
                count++; 
            } 
            else { 
                en++; 
                count--; 
            }
            res=max(res,count); 
        } 
        return res; 
    }
};
