class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
         int st=arr[start];
         int n=arr.size();
         queue<pair<int,int>>q;
         q.push({start,st});
         vector<int>vis(arr.size(),0);
         vis[start]=1;
         while(!q.empty()){
              auto [i,node]=q.front();
              q.pop();
              if(node==0) return true;
              if(i+node<n){
                  if(vis[i+node]==0){
                     vis[i+node]=1;
                     q.push({i+node,arr[i+node]});
                  }
              }
              if(i-node>=0){
                 if(vis[i-node]==0){
                     vis[i-node]=1;
                     q.push({i-node,arr[i-node]});
                 }
              }
         }
         return false;
    }
};