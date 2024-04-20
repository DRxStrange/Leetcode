class Solution {
public:
    int drow[4] = {0,1,0,-1};
    int dcol[4] = {1,0,-1,0};
    void dfs(int row, int col, int n, int m,int &x1,int &y1, int &x2, int &y2, vector<vector<int>> &vis, vector<vector<int>> &land){
        vis[row][col] =1;
        x1 = min(x1,row);
        x2 = max(x2 ,row);
        y1 = min(y1,col);
        y2 = max(y2,col);
        for(int i = 0;i<4;i++){
            int nrow = drow[i]+row;
            int ncol = dcol[i]+col;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol <m){
                if(!vis[nrow][ncol] && land[nrow][ncol]==1){
                    dfs(nrow,ncol,n,m,x1,y1,x2,y2,vis,land);
                }
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
         vector<vector<int>> ans,vis(n,vector<int>(m,0));
        for(int i=0; i<n;i++){
            for( int j=0;j<m;j++){
                
                if(land[i][j] == 1 && !vis[i][j]){
                    int x1 = INT_MAX , x2=0, y1=INT_MAX, y2=0;
                    dfs(i,j,n,m,x1,y1,x2,y2,vis,land);
                    ans.push_back({x1,y1,x2,y2});
                }
            }
        }
       
 return ans;
    }
};