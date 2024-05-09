class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
       long long ans = 0;
       int count =0 ;
        sort(arr.begin(),arr.end(),greater<int>());
        for(int i =0;i<k;i++){
            ans += max(arr[i]-count,0);
            count++;
        }
        return ans;
    }
};