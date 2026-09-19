class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefMax(n), suffMax(n);
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], height[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            suffMax[i] = max(suffMax[i + 1], height[i + 1]);
        }
        int total = 0;
        for (int i = 0; i < n; i++) {
            int h = height[i];
            total += max(0, (min(suffMax[i], prefMax[i]) - h));
        }
        return total;
    }
};
