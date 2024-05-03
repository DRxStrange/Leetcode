class Solution {
public:
    int n,m;
    
    int solve(int i, int j,vector<vector<int>> &mat, vector<vector<int>> &dp){
        if(i >= n || j < 0 || j >= m) return 1e9;
        if(i == n-1){
            return mat[i][j];
        }

        if(dp[i][j] != -1e9) return dp[i][j];

        int left = mat[i][j] + solve(i+1,j-1,mat,dp);
        int right = mat[i][j] + solve(i+1,j+1,mat,dp);
        int down = mat[i][j] + solve(i+1,j,mat,dp);

        return dp[i][j]=min(left,min(right,down));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1e9));

        int mini = INT_MAX;
        for(int i = 0;i<m;i++){
             mini = min(mini,solve(0,i,matrix,dp));
        }
        return mini;
    }
};