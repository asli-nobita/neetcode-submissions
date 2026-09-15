class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        vector<int> ans;
        deque<int> q;
        for (int r = 0; r < n; r++) {
            while (!q.empty() && nums[q.back()] < nums[r]) 
                q.pop_back(); 
            q.push_back(r);
            if (r - l + 1 == k) {
                ans.push_back(nums[q.front()]);
                if (q.front() == l) q.pop_front();
                l++; 
            }
        }
        return ans;
    }
};
