class Solution {
public:
    int jump(vector<int>& nums) {
         queue<pair<int,int>>q;
         int n=nums.size();
         vector<int>vis(n,0);
         vis[0]=1;
         q.push({0,0});
         while(!q.empty()){
              auto[d,node]=q.front();
              q.pop();
              if(node==n-1){
                   return d;
              }
              for(int j=0;j<=nums[node];j++){
                  if(node+j<n){
                      if(vis[node+j]==0){
                          vis[node+j]=1;
                          q.push({d+1,node+j});
                      }
                  }
              }
         }
         return -1;
    }
};