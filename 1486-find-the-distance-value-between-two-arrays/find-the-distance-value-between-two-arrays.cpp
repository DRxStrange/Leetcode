class Solution {
public:
    bool solve(vector<int> &b, int m, int a, int d){
        int low = 0, high = m-1;
        while(low<=high){
            int mid = (low+high)/2;
            int dis = abs(a-b[mid]);
            if(dis <= d){
                return false;
            }else if(b[mid]< a){
               low = mid+1;
            }else{
                high = mid-1;
            }
            
        }
        return true;
    }
    int findTheDistanceValue(vector<int>& a, vector<int>& b, int d) {
         int n = a.size();
         int m = b.size();
         sort(b.begin(),b.end());
        \
         int count =0;
         for(int i =0;i<n;i++){
             if(solve(b,m,a[i],d))
              count++;
             
         }
         return count;
    }
};