class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
          priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
          vector<vector<int>>dist(n,vector<int>(k,INT_MAX));
          vector<vector<pair<int,int>>>adj(n);
          for(auto it:edges){
              adj[it[0]].push_back({it[1],it[2]});
          }
          dist[0][k-1]=0;
          q.push({0,0,k-1});
          while(!q.empty()){
              auto [d,node,rem]=q.top();
              q.pop();
              if(node==n-1){
                     if(rem<=k)
                       return d;
                  
              }
              for(auto nei:adj[node]){
                  int newrem=rem;
                  if(labels[node]==labels[nei.first]){
                     newrem--;
                  }else{
                    newrem=k-1;
                  }
                  if(newrem<0) continue;
                  int nd=d+nei.second;
                  if(nd<dist[nei.first][newrem]){
                     dist[nei.first][newrem]=nd;
                     q.push({nd,nei.first,newrem});
                  }
              }
          }
    return -1;
    }
};