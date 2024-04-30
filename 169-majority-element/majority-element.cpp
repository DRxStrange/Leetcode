class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int temp;
        int count =0;
        int n = nums.size();
        for(int i=0;i<n;i++){

            if(nums[i] == temp){
                count++;
            }
            
            else if(count == 0){
                count=1;
               temp = nums[i];
            }
            else{
                count--;
            }
        }
        count =0;
        for(int i =0;i<n;i++)
        {
            if(temp == nums[i]){
                count++;
            }
        }
        if(count > n/2){
            return temp;
        }
        return -1;
    }
};