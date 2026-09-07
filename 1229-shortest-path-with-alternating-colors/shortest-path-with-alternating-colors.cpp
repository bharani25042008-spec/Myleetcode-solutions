class Solution {
public:
int func(int tar,vector<vector<pair<int,int>>>&adj,int n){
        queue<tuple<int,int,int>>q;
           vector<vector<int>>vis(n,vector<int>(2,0));
           vis[0][1]=1;
           vis[0][0]=0;
           q.push({0,0,0});
           q.push({0,1,0});
           while(!q.empty()){
              auto[node,col,dist]=q.front();
              q.pop();
              if(node==tar){
                  return dist;
              }
              for(auto nei:adj[node]){
                    if(vis[nei.first][nei.second]==1) continue;
                    if(col==nei.second) continue;
                    vis[nei.first][nei.second]=1;
                    q.push({nei.first,nei.second,dist+1});
              }
           }
           return -1;
}
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
           vector<vector<pair<int,int>>>adj(n);
           for(auto it:redEdges){
                adj[it[0]].push_back({it[1],0});
           }
           for(auto it:blueEdges){
                adj[it[0]].push_back({it[1],1});
           }
           vector<int>ans(n);
           for(int i=0;i<n;i++){
             ans[i]=func(i,adj,n);
           }
      return ans;
    }
};