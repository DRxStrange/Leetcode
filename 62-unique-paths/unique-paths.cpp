class Solution {
public:
    // int solve(int i, int j, vector<vector<int>> &dp){
    //     if(i==0 && j==0) return 1;
    //     if(i<0 || j < 0) return 0;
    //      if(dp[i][j] !=-1) return dp[i][j];
    //     int down = solve(i-1,j,dp);
    //     int right = solve(i,j-1,dp);
    //     return dp[i][j] = down + right;

    // }   
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        // return solve(m-1,n-1,dp);
        dp[0][0] = 1;
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){

                if(i==0 || j ==0){
                    dp[i][j] =1;
                }
            }
        }
        for(int i = 1;i<m;i++){
            for(int j =1;j<n;j++){
                int down = dp[i-1][j];
                int right = dp[i][j-1];
                dp[i][j] = down + right;
            }
        }
        return dp[m-1][n-1];
    }
};