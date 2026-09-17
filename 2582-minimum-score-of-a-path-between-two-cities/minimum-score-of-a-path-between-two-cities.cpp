class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
         vector<int>vis(n+1,0);
         vis[1]=1;
         queue<int>q;
         q.push(1);
         int mini=INT_MAX;
         vector<vector<pair<int,int>>>adj(n+1);
         for(auto it:roads){
               adj[it[0]].push_back({it[1],it[2]});
               adj[it[1]].push_back({it[0],it[2]});
         }
         while(!q.empty()){
             int node=q.front();
             q.pop();
             for(auto nei:adj[node]){
                  mini=min(mini,nei.second);
                  if(vis[nei.first]==1) continue;
                  vis[nei.first]=1;
                  q.push(nei.first);
         }
         }
         return mini;
    }
};