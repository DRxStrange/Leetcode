class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int profit = 0;
        int n = prices.size();
        for(int i=0;i<n;i++){
            if(mini>prices[i]){
                mini = prices[i];
            }
            profit = max(profit, prices[i]-mini);
        }
        return profit;
    }
};