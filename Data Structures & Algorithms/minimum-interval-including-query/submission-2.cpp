class Solution {
   public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size(), m = queries.size();
        vector<vector<int>> newQueries;
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            newQueries.push_back({queries[i], i});
        }
        sort(newQueries.begin(), newQueries.end());
        sort(intervals.begin(), intervals.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int i = 0;
        for (int j = 0; j < m; j++) {
            int query = newQueries[j][0], idx = newQueries[j][1];
            // add new valid intervals
            while (i < n && intervals[i][0] <= query) { 
                pq.push({intervals[i][1]-intervals[i][0]+1, intervals[i][1]});
                i++; 
            }
            // remove invalid intervals
            while (!pq.empty() && pq.top().second < query) pq.pop();  
            if (pq.empty())
                ans[idx] = -1;
            else
                ans[idx] = pq.top().first;
        }
        return ans;
    }
};
