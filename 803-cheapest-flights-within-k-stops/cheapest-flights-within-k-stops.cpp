class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        dist[src][k+1]=0;
        q.push({0,src,k+1});
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
              adj[it[0]].push_back({it[1],it[2]});
        }
        while(!q.empty()){
              auto [d,node,rem]=q.top();
              q.pop();
              if(node==dst){
                 if(rem<=k){
                      return d;
                 }
              }
              for(auto nei:adj[node]){
                   int nd=d+nei.second;
                   int newrem=rem;
                   newrem--;
                   if(newrem<0) continue;
                   if(nd<dist[nei.first][newrem]){
                       dist[nei.first][newrem]=nd;
                       q.push({nd,nei.first,newrem});
                   }
              }
        }
        return -1;
    }
};