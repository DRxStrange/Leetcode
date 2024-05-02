class Solution {
public:
int solve(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
       
        dp[1] = nums[0]; 
        
       
        for(int i = 2;i <= n;i++){ 
            
            int pick = nums[i-1]+dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick,notPick);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1) return nums[0];
        vector<int> arr1,arr2;
         for(int i=0; i<n; i++){
        
        if(i!=0) arr1.push_back(nums[i]);
        if(i!=n-1) arr2.push_back(nums[i]);
    }
        int ans1 = solve(arr1);
        int ans2 = solve(arr2);
           int res = max(ans1,ans2);
        return res;
    }
};