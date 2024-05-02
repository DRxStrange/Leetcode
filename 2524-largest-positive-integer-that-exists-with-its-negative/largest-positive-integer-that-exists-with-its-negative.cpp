class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(auto it:nums){
            if(it >0){
                mp[it] =1;
            }
        }
        int maxi =-1;
        for(auto it:nums){
            if(mp.find(-it)!=mp.end()){
                if(maxi<abs(it)){
                    maxi = abs(it);
                }
            }
        }
        return maxi;
    }
};