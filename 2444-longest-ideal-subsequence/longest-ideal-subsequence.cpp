class Solution {
public:
    int k1;
    int rec(int i, string &s, int prev, vector<vector<int>> &dp){
        if(i == s.size()){
            return 0;
        }

        if(prev != -1 && dp[i][prev] != -1)
            return dp[i][prev];

        int c1 = rec(i+1, s, prev, dp);//not include
        int c2 = 0;

        if((prev != -1 && abs(s[i] - 'a' - prev) <= k1) || prev == -1)
            c2 = 1 + rec(i+1, s, s[i] - 'a', dp);
            
        if(prev != -1)
            dp[i][prev] = max(c1, c2);
        return max(c1, c2);
    }
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int> (26, -1));
          k1 = k;
        return rec(0, s, -1, dp);
    }
};