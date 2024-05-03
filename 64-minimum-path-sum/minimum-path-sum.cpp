class Solution {
public:
        int n;
        int m;
    int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid){
        if(i >=n  || j >=m) return 1e9;

        if(i == n-1 && j == m-1) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = grid[i][j]+solve(i+1,j,dp,grid);
        int right = grid[i][j]+solve(i,j+1,dp,grid);
        return dp[i][j] = min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,dp,grid);
    }
};