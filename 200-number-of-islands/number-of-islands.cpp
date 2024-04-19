class Solution {
public:
    const int drow[4] = {0,1,-1,0};
    const int dcol[4] = {1,0,0,-1};

    void dfs(int row, int col, int n ,int m, vector<vector<int>> &vis,
    vector<vector<char>>& grid){
        
       vis[row][col] = 1;

       for(int i=0;i<4;i++){
            int nrow = drow[i]+row;
            int ncol = dcol[i]+col;

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                    dfs(nrow,ncol,n,m,vis,grid);
                }
            }

        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int  m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(i,j,n,m,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};