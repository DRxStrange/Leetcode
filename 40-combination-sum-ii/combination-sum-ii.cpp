class Solution {
public: 
void helper(int ind, int n, int target, vector<int> &arr, vector<vector<int>> &res,vector<int> &ds){
    
        if(target==0){
            res.push_back(ds);
        }
    for(int i=ind;i<n;i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;
        ds.push_back(arr[i]);
        helper(i+1,n,target-arr[i],arr,res,ds);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        vector<int> ds;
        int n = arr.size();
        helper(0,n,target,arr,res,ds);
        
        return res;
    }
};