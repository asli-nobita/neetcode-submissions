class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minlen = n + 1;
        int l = 0;
        int currSum = 0;
        for (int r = 0; r < n; r++) {
            currSum += nums[r];
            while (l <= r && currSum >= target) {
                minlen = min(minlen, r - l + 1);
                currSum -= nums[l];
                l++;
            }
        }
        return minlen == n + 1 ? 0 : minlen;
    }
};