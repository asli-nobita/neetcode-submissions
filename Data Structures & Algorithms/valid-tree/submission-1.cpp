class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false; 
        vector<int> vis(n); 
        vector<vector<int>> adj(n); 
        for(auto e:edges) { 
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);  
        }
        dfs(0,vis,adj); 
        for(int i=0;i<n;i++) { 
            if(!vis[i]) return false; 
        } 
        return true; 
    }
private: 
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj) { 
        if(vis[node]) return; 
        vis[node]=1;
        for(int adjNode:adj[node]) { 
            dfs(adjNode,vis,adj); 
        }
    }
};
