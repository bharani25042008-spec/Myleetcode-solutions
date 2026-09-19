class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
              mp[arr[i]].push_back(i);
        }
          vector<int>vis(n,0);
          vis[0]=1;
          queue<pair<int,int>>q;
          q.push({0,0});
          while(!q.empty()){
               auto[d,i]=q.front();
               q.pop();
               if(i==n-1) return d;
               if(i-1>=0){
               if(vis[i-1]==0){
                   vis[i-1]=1;
                   q.push({d+1,i-1});
               }
               }
               if(i+1<n){
                   if(vis[i+1]==0){
                      vis[i+1]=1;
                      q.push({d+1,i+1});
                   }
               }
               for(auto it:mp[arr[i]]){
                  if(vis[it]==0&&it!=i){
                      vis[it]=1;
                      q.push({d+1,it});
                  }
               }
               mp[arr[i]].clear();
          }
     return 0;
    }
};