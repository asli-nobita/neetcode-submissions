class Solution {
public:

    string encode(vector<string>& strs) {
        string ans=""; 
        for(string s:strs) { 
            ans.append(s); 
            ans.append("."); 
        } 
        return ans; 
    }

    vector<string> decode(string s) {
        int st=0;
        int n=s.length(); 
        vector<string> ans; 
        for(int i=0;i<n;i++) { 
            st=i; 
            while(i<n && s[i]!='.') i++; 
            ans.push_back(s.substr(st,i-st)); 
        }
        return ans; 
    }
};
