class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prefMax(n); 
        vector<int> suffMax(n);
        int maxPref=INT_MIN,maxSuff=INT_MIN; 
        for(int i=0;i<n-1;i++) { 
            maxPref=max(maxPref,height[i]); 
            prefMax[i+1]=maxPref;
        } 
        for(int i=n-1;i>=1;i--) { 
            maxSuff=max(maxSuff,height[i]); 
            suffMax[i-1]=maxSuff; 
        }
        int ans=0; 
        for(int i=0;i<n;i++) { 
            ans+=max((min(prefMax[i],suffMax[i])-height[i]),0); 
        }
        return ans;
    }
};
