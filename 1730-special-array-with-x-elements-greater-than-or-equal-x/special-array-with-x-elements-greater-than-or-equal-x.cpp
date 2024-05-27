class Solution {
public:
int bs(vector<int> &arr, int val){
    int s = 0;
    int e = arr.size()-1;
    int index = arr.size();
    while(s<=e){
       int mid = (s+e)/2;
       if(arr[mid]>= val){
        index = mid;
        e =  mid-1;
       }   else{
        s = mid+1;
       }
    }
    return index;
}
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<=n;i++){
            int c = bs(nums,i);
            if(n-c == i){
                return i;
            }
        }
        return -1;
    }
};