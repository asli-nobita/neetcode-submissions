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
        sort(intervals.begin(),intervals.end(),[](auto& a,auto& b) { 
            return a.end<b.end; 
        }); 
        for(auto i:intervals) cout<<"( "<<i.start<<" "<<i.end<<" ) ";
        int n=intervals.size(); 
        vector<int> days;
        days.push_back(intervals[0].end); 
        for(int i=1;i<n;++i) { 
            bool overlap=true;
            auto intrvl=intervals[i];
            int m=days.size();  
            for(int j=0;j<m;++j) { 
                if(intrvl.start>=days[j]) { 
                    days[j]=intrvl.end; 
                    overlap=false;
                    break; 
                }
            } 
            if(overlap) days.push_back(intrvl.end); 
        }
        return days.size();
    }
};
