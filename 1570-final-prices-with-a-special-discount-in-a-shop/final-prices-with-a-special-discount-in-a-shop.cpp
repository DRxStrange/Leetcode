class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n,0);
        ans[n-1] = prices[n-1];
        int i=0;
        while(i<n-1){
            int j = i+1;
            int flag = false;
            while(j<n){
            if(prices[j] <= prices[i]){
                int dis = prices[i] - prices[j];
                ans[i]= dis;
                flag = true;
                break;
            }
            j++;
        }
        if(!flag){
            ans[i] = prices[i];
        }
              i++;  
        }
        return ans;
    }
};