class Solution {
public:
//i just wanted to quit these stuffs and go for poultry farming
bool func(int &x,int &n,vector<bool>&online,vector<vector<pair<int,int>>>&adj,long long &k){
          vector<long long>dist(n,LLONG_MAX);
          dist[0]=0;
          priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
          pq.push({0,0});
          while(!pq.empty()){
               auto [d,node]=pq.top();
               pq.pop();
               if(d != dist[node]) continue;
               if(node==n-1){
                  return d<=k;
               }
               for(auto nei:adj[node]){
                     if(online[nei.first]==false) continue;
                     if(nei.second<x) continue;
                     long long nd=d+nei.second;
                     if(nd<dist[nei.first]){
                           dist[nei.first]=nd;
                           pq.push({nd,nei.first});
                     }
               }
          }
          return false;
}
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
            int l=0;
            int r=0;
            int n=online.size();
            int ans=-1;
            vector<vector<pair<int,int>>>adj(n);
            for(auto it:edges){
                //    r=max(r,it[0]);
                   r=max(r,it[2]);
                   adj[it[0]].push_back({it[1],it[2]});
            }
            while(l<=r){
                  int mid=(l+r)/2;
                  if(func(mid,n,online,adj,k)){
                       ans=mid;
                       l=mid+1;
                  }else{
                       r=mid-1;
                  }
            }
        return ans;
    }
};