class Solution {
public:
    bool divisorGame(int n) {
         vector<bool> dp(n+1,0);
         dp[0]=0;
         dp[1]=0;
         
         for(int i=2;i<=n;i++){
             for(int x = 1;x<i;x++){
                if(i%x==0 && !dp[i-x]){
                    dp[i]= 1;
                    break;
                }
             }
         }
         return dp[n];
    }
};