class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;
        int ans = 0;
        while (l < r) {
            int area = (r - l) * min(heights[r], heights[l]);
            ans = max(area, ans);
            if (heights[r] < heights[l])
                r--;
            else
                l++;
        }
        return ans;
    }
};
