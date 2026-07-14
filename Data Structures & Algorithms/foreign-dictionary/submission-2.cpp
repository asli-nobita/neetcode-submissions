class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n=words.size(); 
        unordered_map<char,vector<char>> adj; 
        unordered_map<char,bool> vis;

        for(auto& word:words) { 
            for(auto ch:word) { 
                adj[ch]; 
            }
        }

        for(int i=0;i<n-1;i++) { 
            string word1=words[i],word2=words[i+1]; 
            int m=min(word1.length(),word2.length()); 
            for(int j=0;j<m;j++) { 
                if(word1[j]!=word2[j]) { 
                    adj[word1[j]].push_back(word2[j]); 
                    break; 
                } 
                if(j==m-1 && word1.length()>word2.length()) return ""; 
            } 
        } 
        string res; 
        for(const auto& entry:adj) { 
            if(dfs(entry.first,res,vis,adj)) return ""; 
        }
        reverse(res.begin(),res.end()); 
        return res; 
    }

    bool dfs(char c,string& res,unordered_map<char,bool>& vis,unordered_map<char,vector<char>>& adj) { 
        if(vis.find(c)!=vis.end()) return vis[c]; 
        vis[c]=true; 
        for(char nei:adj[c]) { 
            if(dfs(nei,res,vis,adj)) return true; 
        } 
        vis[c]=false; 
        res.push_back(c); 
        return false; 
    }
};
