class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
         unordered_map<int,int> mp;
         int size = arr.size();
         for(int i= 0;i<size;i++){
            int rem = target - arr[i];
            if(mp.find(rem)!=mp.end()){
                return {mp[rem],i};
            }
            else{
                mp[arr[i]] = i;
            }
         }
         return {-1,-1};
    }
};