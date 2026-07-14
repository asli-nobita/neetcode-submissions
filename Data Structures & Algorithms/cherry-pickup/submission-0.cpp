class Solution { 
    vector<vector<vector<int>>> dp; 
public:
    int dfs(int r1, int c1, int r2, vector<vector<int>>& grid) { 
        int n=grid.size(); 
        int c2=r1+c1-r2; 
        if(r1 >= n || c1 >= n || r2>=n || c2>=n || 
        grid[r1][c1]==-1 || grid[r2][c2]==-1) { 
            return INT_MIN; 
        } 
        if(r1 == n-1 && c1 == n-1) { 
            return grid[r1][c1]; 
        } 
        if(dp[r1][c1][r2] != -1) {
            return dp[r1][c1][r2];
        } 

        int res=grid[r1][c1]; 
        if(!(r2==r1 && c2==c1)) res+=grid[r2][c2]; 
        res+=max({
            dfs(r1+1,c1,r2+1,grid), 
            dfs(r1,c1+1,r2,grid), 
            dfs(r1,c1+1,r2+1,grid), 
            dfs(r1+1,c1,r2,grid)
        }); 
        return dp[r1][c1][r2]=res; 
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(); 
        dp.assign(n, vector<vector<int>>(n, vector<int>(n, -1))); 
        return max(0, dfs(0,0,0,grid)); 
    }
};