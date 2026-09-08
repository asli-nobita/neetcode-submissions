class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (auto c : coins) {
            for (int amt = c; amt <= amount; amt++) {
                dp[amt] += dp[amt - c];
            }
        }
        return dp[amount];
    }
};
