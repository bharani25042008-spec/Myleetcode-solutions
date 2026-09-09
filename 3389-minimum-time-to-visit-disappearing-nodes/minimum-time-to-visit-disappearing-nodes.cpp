class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
         vector<vector<pair<int,int>>>adj(n);
         for(auto it:edges){ 
              adj[it[0]].push_back({it[1],it[2]});
              adj[it[1]].push_back({it[0],it[2]});
         }
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
          vector<int>dist(n,INT_MAX);
          dist[0]=0;
          q.push({0,0});
          while(!q.empty()){
              auto[d,node]=q.top();
              q.pop();
              if(d != dist[node])
                continue;
              for(auto nei:adj[node]){
                    int nd=d+nei.second;
                    if(nd<dist[nei.first]&&nd<disappear[nei.first]){
                          dist[nei.first]=nd;
                          q.push({nd,nei.first});
                    }
              }
          }
          vector<int>ans(n);
          for(int i=0;i<n;i++){
              if(dist[i]==INT_MAX){
                  ans[i]=-1;
              }else{
                  ans[i]=dist[i];
              }
          }
          return ans;
    }
};