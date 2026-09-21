class Solution {
public:
    int jump(vector<int>& nums) {
          int n=nums.size();
          queue<pair<int,int>>q;
          q.push({0,0});
          vector<int>vis(n,0);
          vis[0]=1;
          while(!q.empty()){
              auto [d,node]=q.front();
              q.pop();
              if(node==n-1) return d;
              for(int i=1;i<=nums[node];i++){
                  if(i+node<n){
                     if(vis[i+node]==0){
                         vis[i+node]=1;
                         q.push({d+1,i+node});
                     }
                  }
              }
          }
          return -1;
    }
};