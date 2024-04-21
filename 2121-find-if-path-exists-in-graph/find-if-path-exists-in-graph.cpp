class Solution {
public:
bool dfs(int s, int d, vector<int> &vis, vector<int> adj[]){
    if(s == d) return true;
    vis[s] = 1;
    for(auto it : adj[s]){
        if(!vis[it]){
            if(dfs(it, d,vis,adj)) return true;
        }
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {              
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i =0;i<n;i++){
           if(i==s){
            return dfs(i,d,vis,adj);
           }
        }
        return false;
    }
};