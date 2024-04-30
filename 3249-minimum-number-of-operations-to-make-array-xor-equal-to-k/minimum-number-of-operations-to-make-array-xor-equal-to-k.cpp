class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorr = 0;
        for(auto it : nums){
            xorr = xorr ^ it;
        }
        int count = 0;
        xorr = xorr ^ k;
        while(xorr > 0){
         count += (xorr & 1);
         xorr = xorr >> 1;
        }
        return count;
    }
};