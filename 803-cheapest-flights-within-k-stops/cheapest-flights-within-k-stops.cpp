class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
           vector<vector<pair<int,int>>>adj(n);
           for(auto it:flights){
                int f=it[0];
                int t=it[1];
                int c=it[2];
                adj[f].push_back({t,c});
           }

           priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
           q.push({0,src,k+1});
           vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
           dist[src][k+1]=0;
           while(!q.empty()){
             auto [d,node,rem]=q.top();
             q.pop();
             if(node==dst){
                 return d;
             }
             for(auto nei:adj[node]){
                int newrem=rem;
                newrem--;
                if(newrem<0){
                     continue;
                }
                  int newcost=d+nei.second;
                  if(newcost<dist[nei.first][newrem]){
                    dist[nei.first][newrem]=newcost;
                    q.push({newcost,nei.first,newrem});
                  }
             }
           }
           return -1;
    }
};