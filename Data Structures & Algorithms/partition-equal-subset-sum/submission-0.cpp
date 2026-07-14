class Solution {
public: 
    bool func(vector<int>& nums,int i,int sum,int arraySum) {  
        if(sum==arraySum/2) return true; 
        if(i==nums.size() || sum>arraySum/2) return false; 
        return func(nums,i+1,sum+nums[i],arraySum) || func(nums,i+1,sum,arraySum); 
    }
    bool canPartition(vector<int>& nums) {
        int arraySum=0;  
        for(int num:nums) arraySum+=num;  
        if(arraySum%2 == 1) return false; 
        return func(nums,0,0,arraySum); 
    }
};

