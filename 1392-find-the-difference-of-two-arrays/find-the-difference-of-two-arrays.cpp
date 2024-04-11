class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
       
        int n = nums1.size();
        int m = nums2.size();
        for(auto it : nums1){
            s1.insert(it);
        }
        for(auto it: nums2){
            s2.insert(it);
        }
        for(auto it: nums2){
            if(s1.find(it) !=s1.end()){
                s1.erase(it);
            }
        }
        
        for(auto it: nums1){
            if(s2.find(it) !=s2.end()){
                s2.erase(it);
            }
        }
        
        
        vector<int> ans1, ans2;

            for (auto it : s1) {
                ans1.push_back(it);
                }
                for (auto it: s2) {
                ans2.push_back(it);
                }
                return {ans1,ans2};
    }
};