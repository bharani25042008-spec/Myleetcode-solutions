class Solution {
public:
int c(int th,int node){
       if(th<node) return 1;
       return 0;
}
bool func(int t,vector<vector<pair<int,int>>>&adj,int s,int tar,int k,int n){

       vector<int>dist(n,INT_MAX);
       dist[s]=0;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
       q.push({0,s});
       while(!q.empty()){
           auto [d,node]=q.top();
           q.pop();
           if(node==tar){
               if(d<=k){
                   return true;
               }
           }
           for(auto nei:adj[node]){
                int nd=d+c(t,nei.second);
                if(nd<dist[nei.first]){
                     dist[nei.first]=nd;
                     q.push({nd,nei.first});
                }
           }
       }
       return false;
}
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
          vector<vector<pair<int,int>>>adj(n);
          for(int i=0;i<edges.size();i++){
             adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
             adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
          }
          int ans=-1;
          int l=0;
          int r=0;
          for(int i=0;i<edges.size();i++){
               r=max(r,edges[i][0]);
               r=max(r,edges[i][1]);
               r=max(r,edges[i][2]);
          }
          while(l<=r){
              int mid=(l+r)/2;
              if(func(mid,adj,source,target,k,n)){
                   ans=mid;
                   r=mid-1;
              }
              else{
                  l=mid+1;
              }
          }
          return ans;
    }
};