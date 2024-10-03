class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        int n = nums.size();
        // calculate total sum and target remainder
        for(int num : nums){
            sum = (sum + num) % p;
        }
        int target = sum % p;
        // the array already divisible of P
        if(target == 0) return 0;
// use hash map to track prefix sum mod p
     unordered_map<int,int> mp;
     mp[0] =-1;
     int currSum = 0, minLen = n;
    //  iterate over array
    for(int i=0;i<n;i++){
          currSum = (currSum + nums[i]) % p;
        int needed = (currSum - target + p) % p;

        if(mp.find(needed) != mp.end()){
            minLen = min(minLen, i - mp[needed]);
        }

        mp[currSum] = i;
    }
          return minLen == n ? -1 : minLen;
    }
};