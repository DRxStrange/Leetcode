class Solution {
public:
    // void solve(vector<int> &b, int m, int a, int d, int &count){
    //     int low = 0, high = m-1;
    //     while(low<=high){
    //         int mid = (low+high)/2;
    //         int dis = abs(a-b[mid]);
    //         if(dis <= d){
    //             low = mid-1;
    //             count++;
    //         }else{
    //             high = mid+1;
    //         }
            
    //     }
    //     return ;
    // }
    int findTheDistanceValue(vector<int>& a, vector<int>& b, int d) {
         int n = a.size();
         int m = b.size();
         sort(b.begin(),b.end());
        \
         int count =0;
         for(int i =0;i<n;i++){
             bool flag = false;
             for(int j =0;j<m;j++){
                if(abs(a[i]-b[j]) <= d){
                   flag = true;
                   break;
                }
             }
             if(!flag){
                count++;
             }
         }
         return count;
    }
};