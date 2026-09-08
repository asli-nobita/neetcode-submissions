class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> best;
        for (auto num : nums) {
            if (best.empty() || num > best.back())
                best.push_back(num);
            else {
                auto it = lower_bound(best.begin(), best.end(), num);
                *it = num;
            }
        }
        return best.size();
    }
};
