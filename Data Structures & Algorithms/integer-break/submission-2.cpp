class Solution { 
    vector<int> memo; 
   public:
    int dfs(int n) {
        // max prod if we break n into k integers
        if (n == 1) return n; 
        if (memo[n] != -1) return memo[n]; 
        int prod = 1; 
        for (int i = 1; i < n; i++) { 
            prod = max(prod, max(i, dfs(i)) * max(n - i, dfs(n - i)));
        }
        return memo[n] = prod;
    }
    int integerBreak(int n) {  
        memo.assign(59,-1); 
        return dfs(n);  
    }
};