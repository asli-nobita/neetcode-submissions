class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n=s.length(); 
        unordered_map<char, int> unique; 
        int l=0; 
        int maxlen=0; 
        for(int r=0;r<n;r++) { 
            unique[s[r]]++; 
            if(unique.size()<=k) { 
                maxlen=max(maxlen, r-l+1);  
            }
            else { 
                unique[s[l]]--; 
                if(unique[s[l]]==0) unique.erase(s[l]); 
                l++; 
            }
        }
        return maxlen; 
    }
};
