class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
           vector<vector<pair<int,int>>>adj(n);
           for(auto it:edges){
               adj[it[0]].push_back({it[1],it[2]});
               adj[it[1]].push_back({it[0],2*it[2]});
           }
           vector<int>dist(n,INT_MAX);
           dist[0]=0;
           priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
           q.push({0,0});
           while(!q.empty()){
                auto[d,node]=q.top();
                q.pop();
                if(node==n-1){
                      return d;
                }
                for(auto nei:adj[node]){
                     int nd=d+nei.second;
                     if(nd<dist[nei.first]){
                          dist[nei.first]=nd;
                          q.push({nd,nei.first});
                     }
                }
           }
           return -1;
    }
};