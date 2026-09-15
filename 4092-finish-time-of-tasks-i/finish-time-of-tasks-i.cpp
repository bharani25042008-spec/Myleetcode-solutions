class Solution {
public:
const int mod=1e9+7;
__int128 func(int node,vector<vector<int>>&adj,vector<int>&b,map<int,__int128>&mp){
      if(mp.find(node)!=mp.end()){
           return mp[node];
      }
      if(adj[node].size()==0){
             return mp[node]=b[node];
      }
    __int128 maxi=LLONG_MIN;
    __int128 mini=LLONG_MAX;
      for(auto it:adj[node]){
                __int128 val=func(it,adj,b,mp);
                maxi=max(maxi,val);
                mini=min(mini,val);
               }  
      return mp[node]=(maxi+((maxi-mini)+(__int128)b[node]));
      //tree dp duh
}
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
          vector<vector<int>>adj(n);

          map<int,__int128>mp;
          for(auto it:edges)
          {
              adj[it[0]].push_back({it[1]});
          }
          for(int i=n-1;i>=0;i--){
                if(mp.find(i)!=mp.end()){
                      continue;
                }else{
                    mp[i]=func(i,adj,baseTime,mp);
                }
          }
        //   for(auto it:mp){
        //      cout<<it.first<<":"<<it.second<<' ';
        //   }
          return mp[0];

    }
};