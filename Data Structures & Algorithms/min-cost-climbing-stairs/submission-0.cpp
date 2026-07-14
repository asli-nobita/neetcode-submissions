class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) { 
        int n=cost.size(); 
        vector<int> arr(n); 
        arr[n-1]=cost[n-1]; 
        arr[n-2]=cost[n-2]; 
        for(int i=n-3;i>=0;i--) { 
            arr[i]=cost[i]+min(arr[i+1],arr[i+2]); 
        } 
        return min(arr[0],arr[1]); 
    }
};
