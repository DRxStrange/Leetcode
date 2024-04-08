class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int k) {
    
    unordered_map<int,int> mp;
    for(int i =0; i<arr.size();i++){
        int temp = arr[i];
        if(mp.find(k-temp) != mp.end()){
            return {mp[k-temp], i};
        }
        mp[temp] = i;
    }
       return {};
    }
};