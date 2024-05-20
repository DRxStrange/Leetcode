class Solution {
public:
    int solve(int i,vector<int> &nums, int xo){
      if(i==nums.size()) return xo;

    
    int notPick = solve(i+1,nums,xo);
   
    int pick= solve(i+1,nums,xo^nums[i]);
      return pick + notPick;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        
        return solve(0,nums,0);
    }
};