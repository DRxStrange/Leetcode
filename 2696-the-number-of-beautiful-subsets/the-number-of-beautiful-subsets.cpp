class Solution {
public:
    void  solve(int idx, int n, vector<int> &arr, int k, int &result, unordered_map<int,int> &mp){
        if(idx >= n) {
            result++;
            return;
        }

        solve(idx+1,n,arr,k,result,mp);
        
        int d1 = arr[idx]+k;
        int d2 = arr[idx]-k;
        if(!mp[arr[idx]+k] && !mp[arr[idx]-k]){
            mp[arr[idx]]++;
           solve(idx+1,n,arr,k,result,mp);
            mp[arr[idx]]--;
        }
        
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int result=0;
        unordered_map<int,int> mp;
        solve(0,nums.size(),nums,k,result,mp);
        return result-1;
    }
};