class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
           priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<tuple<int,int>>>q;
           vector<int>dist(n+1,INT_MAX);
           dist[k]=0;
           q.push({0,k});
           vector<vector<pair<int,int>>>adj(n+1);
           for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
           }
           while(!q.empty()){
               auto [d,node]=q.top();
               q.pop();
               for(auto nei:adj[node]){
                  int nd=d+nei.second;
                  if(nd<dist[nei.first]){
                     dist[nei.first]=nd;
                     q.push({nd,nei.first});
                  }
               }
               
           }
           for(int i=1;i<=n;i++){
             if(dist[i]==INT_MAX){
                return -1;
             }
           }
           for(auto it:dist) cout<<it;
           return *max_element(dist.begin()+1,dist.end());
    }
};