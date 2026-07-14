class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n); 
        for(auto e:edges) { 
            adj[e[0]].push_back(e[1]); 
            adj[e[1]].push_back(e[0]);
        } 
        int ans=0;  
        vector<int> vis(n); 
        for(int i=0;i<n;i++) { 
            if(!vis[i]) { 
                ans++; 
                queue<int> q; 
                q.push(i); 
                while(!q.empty()) { 
                    int node=q.front(); 
                    q.pop(); 
                    vis[node]=1; 
                    for(int adjNode:adj[node]) { 
                        if(!vis[adjNode]) { 
                            q.push(adjNode); 
                        }
                    }
                }
            }
        } 
        return ans; 
    }
};
