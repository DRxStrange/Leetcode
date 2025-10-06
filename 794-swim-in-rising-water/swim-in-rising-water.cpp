class Solution {
public:

 vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

   bool possibleToReach(int t, int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &v){
    int n = grid.size();

    if(i < 0 || i >= n || j < 0 || j >= n || v[i][j] == true || grid[i][j] > t ){
        return false;
    }
      v[i][j] = true;

    if(i == n-1 && j == n-1) return true;
    for(auto it : dir){
        int nr = i + it[0];
        int nc = j + it[1];
        if(possibleToReach(t, nr, nc, grid, v)){
            return true;
        }

        
    }
    return false;

   }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int l = grid[0][0];
        int r = n*n - 1;

        int result = 0;

        while(l <= r){
           int mid = l + (r-l)/2;

        vector<vector<bool>> v(n, vector<bool>(n,false));
           if(possibleToReach(mid,0,0,grid,v)){
            result = mid;
            r = mid -1;
           }
           else{
            l = mid + 1;
           }

        }
        return result;
    }
};