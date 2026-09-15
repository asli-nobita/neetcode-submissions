class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        stack<double> stk;
        for (auto [pos, sp] : cars) {
            double time = ((target - pos) * 1.0) / sp; 
            while (!stk.empty() && stk.top() <= time) stk.pop(); 
            stk.push(time);
        }
        return stk.size();
    }
};
