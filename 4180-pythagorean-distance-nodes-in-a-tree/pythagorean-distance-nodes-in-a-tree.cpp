class Solution {
public:
void func(int n,vector<vector<int>>&adj,vector<int>&dist){
           dist[n]=0;
           queue<pair<int,int>>q;
           q.push({0,n});
           while(!q.empty()){
                auto[d,node]=q.front();
                q.pop();
                for(auto nei:adj[node]){
                       int nd=d+1;
                       if(nd<dist[nei]){
                          dist[nei]=nd;
                          q.push({dist[nei],nei});
                       }
                }
           }
}
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
            vector<vector<int>>adj(n);
            for(auto it:edges){
                    adj[it[0]].push_back(it[1]);
                    adj[it[1]].push_back(it[0]);
            }
            vector<int>v1(n,INT_MAX);
            vector<int>v2(n,INT_MAX);
            vector<int>v3(n,INT_MAX);
            func(x,adj,v1);
            func(y,adj,v2);
            func(z,adj,v3);
            int ans=0;
            for(int i=0;i<n;i++){
                  vector<int>t;
                  t.push_back(v1[i]);
                  t.push_back(v2[i]);
                  t.push_back(v3[i]);
                  sort(t.begin(),t.end());
                  if((1LL*t[0]*t[0]+1LL*t[1]*t[1])==(1LL*t[2]*t[2])){
                       ans++;
                  }
            }
        return ans;
    }
};