class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
           queue<tuple<int,int,int>>q;
        //   int n=*max_element(forbidden.begin(),forbidden.end());
        //   n=max(n,a);
        //   n=max(n,b);
        //   n=max(n,x);
          set<int>st(forbidden.begin(),forbidden.end());
          q.push({0,0,2});
          vector<vector<int>>vis(6000,vector<int>(3,0));
          vis[0][2]=1;
          while(!q.empty()){
              auto[d,node,dir]=q.front();
              q.pop();
              if(node==x) return d;
              if(dir==2){
                  if(node+a<6000){
                      if(vis[node+a][1]==0&&st.find(node+a)==st.end()){
                         vis[node+a][1]=1;
                         q.push({d+1,node+a,1});
                      }
                  }
                  if(node-b>=0){
                     if(vis[node-b][0]==0&&st.find(node-b)==st.end()){
                         vis[node-b][0]=1;
                         q.push({d+1,node-b,0});
                     }
                  }
              }
              if(dir!=0){
                  if(node-b>=0){
                     if(vis[node-b][0]==0&&st.find(node-b)==st.end()){
                         vis[node-b][0]=1;
                         q.push({d+1,node-b,0});
                     }
                  }
              }
              if(node+a<6000){
                 if(vis[node+a][1]==0&&st.find(node+a)==st.end()){
                     vis[node+a][1]=1;
                     q.push({d+1,node+a,1});
                 }
              }
          }
          return -1;
    }
};