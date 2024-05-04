class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        sort(arr.begin(),arr.end());
        int count =0;
        int i=0, j=arr.size()-1;
        while(i<=j){
            int val = arr[i]+arr[j];
            if(val <= limit){
                i++;
                j--;
            }
            else {
                j--;
            }
            count++;
        }
        return count;
    }
};