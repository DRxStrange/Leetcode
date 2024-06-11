class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
         map<int,int> mp;
         int n = arr1.size();
         for(int i=0;i<n;i++){
            mp[arr1[i]]++;
         }
         vector<int> ans(arr1.size());
         int  i = 0;
         for(auto it: arr2){
               while(mp[it]-- > 0){
                  ans[i] = it;
                  i++;
               }
         }
         for(auto it:mp){
            int frq = it.second;
            int num = it.first;
               while(frq > 0){
                  ans[i] = num;
                  i++;
                  frq--;
               }
         }
         return ans;
    }
};