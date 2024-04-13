class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
//         created a graph 
        vector<vector<int>> adj[n];
        for(auto it: edges){
            int u,v,w;
            u = it[0];
            v = it[1];
            w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        
        vector<int> dis(n);
        for(int i=0;i<n;i++) dis[i]=1e9;
        
       
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,0});
        
        dis[0]=0;
        while(!pq.empty()){
            
            auto it = pq.top();
            int node =it.second;
            int d = it.first;
            pq.pop();
             if(d > dis[node]) {
                continue;
            }
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgeDis = it[1];
                int currD = d+edgeDis;
                
                
                if(currD < disappear[adjNode] && currD < dis[adjNode]){
                    dis[adjNode] = d+edgeDis;
                    pq.push({dis[adjNode],adjNode});
                }
            }
        }
       for(int i=0;i<n;i++){
           if(dis[i]==1e9){
               dis[i] = -1;
           }
       }
        return dis;
    }
};