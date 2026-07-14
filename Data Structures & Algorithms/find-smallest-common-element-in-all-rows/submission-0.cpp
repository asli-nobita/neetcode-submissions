class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();   
        int lo=0, hi=n-1;
        int ans=-1; 
        while(lo<=hi) { 
            int i=lo+(hi-lo)/2; 
            int target=mat[m-1][i]; 
            bool found=true; 
            for(int j=0;j<m-1;j++) { 
                auto it=lower_bound(mat[j].begin(), mat[j].end(),target); 
                if(it == mat[j].end() || *it != target) { 
                    found=false; 
                    break; 
                } 
            } 
            if(found) { 
                ans=target; 
                hi=i-1; 
            } 
            else { 
                lo=i+1; 
            }
        }
        return ans; 
    }
};
