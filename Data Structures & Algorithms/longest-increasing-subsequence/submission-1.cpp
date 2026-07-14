class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(); 
        vector<int> LIS(n,-1); 
        LIS[n-1]=1;  
        int ans=1; 
        for(int i=n-2;i>=0;i--) { 
            LIS[i]=1; 
            for(int j=i+1;j<n;j++) { 
                if(nums[j]>nums[i]) { 
                    LIS[i]=max(LIS[i],1+LIS[j]); 
                }
            } 
            ans=max(ans,LIS[i]); 
        }  
        return ans; 
    }
};
