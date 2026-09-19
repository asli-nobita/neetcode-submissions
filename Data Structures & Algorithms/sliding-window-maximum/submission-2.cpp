class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, int>> q;  // (val, idx)
        vector<int> ans;
        int l = 0;
        for (int r = 0; r < n; r++) {
            while (!q.empty() && nums[r] > q.back().first) q.pop_back();
            q.push_back({nums[r], r});
            if (r - l + 1 == k) {
                ans.push_back(q.front().first);
                if (q.front().second == l) q.pop_front();
                l++;
            }
        }
        return ans;
    }
};
