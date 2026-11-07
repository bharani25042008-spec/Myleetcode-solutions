class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
              vector<vector<pair<int,int>>>adj(n);
              for(auto it:edges){
                   adj[it[0]].push_back({it[1],it[2]});
              }
              vector<pair<long long ,long long>>ans;
              vector<vector<long long>>dist(n+1,vector<long long>(power+1,LLONG_MAX));
              priority_queue<tuple<long long,long long,long long>,vector<tuple<long long ,long long,long long>>,greater<tuple<long long,long long,long long>>>q;
              q.push({0,source,power});
              dist[source][power]=0;
              while(!q.empty()){
                   auto[d,node,rem]=q.top();
                   q.pop();
                   if(node==target){
                       ans.push_back({d,rem});
                   }
                   for(auto nei:adj[node]){
                       long long newrem=rem;
                       long long c=cost[node];
                       if(c>newrem){
                           continue;
                       }
                       if(newrem<0){
                           continue;
                       }
                       newrem-=c;
                       long long nd=d+(long long)nei.second;
                       if(nd<dist[nei.first][newrem]){
                           dist[nei.first][newrem]=nd;
                           q.push({nd,nei.first,newrem});
                       }
                   }
              }
              long long mini=LLONG_MAX;
              for(auto it:ans){
                   mini=min(mini,it.first);
              }
              long long maxi=0;
              for(auto it:ans){
                   if(it.first==mini){
                       maxi=max(maxi,it.second);
                   }
              }
              if(mini==LLONG_MAX&&maxi==0) return {-1,-1};
              return {mini,maxi};
    }
};