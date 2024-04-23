class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return{0};
          vector<int> adj[n];
        //   find out indegree which node has 1 mean it is leaf node we have remove it
          vector<int> ind(n);
          for(auto it: edges){
            int u = it[0];
            int v = it[1];
            ind[u]++;
            ind[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
          }
          queue<int> q;
        // fill the leaf node 
          for(int i =0;i<n;i++){
            if(ind[i]==1){
                q.push(i);
                }
          }
        int processed = 0;
          while(n - processed > 2){
                int s = q.size();
                processed += s;
                for(int i =0;i<s;i++){
                    int node = q.front();
                    q.pop();
                    for(auto it : adj[node]){
                        if(--ind[it]==1){
                            q.push(it);
                        }
                    }
                }
          }
          vector<int> ans;
          while(!q.empty()){
             int node = q.front();
             q.pop();
             ans.push_back(node);

          }
         return ans;
    }
};