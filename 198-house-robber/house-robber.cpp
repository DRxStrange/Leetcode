class Solution {
public:
    int solve(int ind, vector<int> &arr,vector<int> &dp){
        if(ind <= 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = arr[ind-1]+solve(ind-2,arr,dp);
        int notPick = solve(ind-1,arr,dp);
        dp[ind] = max(pick,notPick);
        return dp[ind];
    } 
    int rob(vector<int>& nums) {
        // int n = nums.size();
        //  vector<int> dp(n+1,-1);
        //  return solve(n,nums,dp);
        int n = nums.size();
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1] = nums[0];
        for(int i =2;i<=n;i++){
            int pick = nums[i-1]+dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick,notPick);
        }
        return dp[n];
    }
};