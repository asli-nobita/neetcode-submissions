class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1,false); 
        dp[s.length()]=true; 
        for(int i=s.length()-1;i>=0;i--) { 
            for(string w:wordDict) { 
                int n=w.length(); 
                int len=s.length()-i; 
                if(len>=n && s.substr(i,n)==w) dp[i]=dp[i+n];
                if(dp[i]==true) break;  
            }
        }
        return dp[0]; 
    }
};
