class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        for (auto num : nums) count[num]++;
        unordered_map<int, vector<int>> freq;
        // freq[i]=all numbers that appear i times
        for (auto [num, f] : count) {
            freq[f].push_back(num);
        }
        vector<int> ans;
        for (int f = n; f >= 1; f--) { 
            if (ans.size()==k) break; 
            for (auto num : freq[f]) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};
