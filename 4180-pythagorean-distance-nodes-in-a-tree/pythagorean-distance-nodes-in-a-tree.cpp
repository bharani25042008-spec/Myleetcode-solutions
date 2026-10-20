class Solution {
public:
void func(int &start,vector<int>&dist,vector<vector<int>>&adj,int &n){
       queue<pair<int,int>>q;
       vector<int>vis(n+1,0);
       vis[start]=1;
       dist[start]=0;
       q.push({0,start});
       while(!q.empty()){
           auto[d,node]=q.front();
           q.pop();
           for(auto nei:adj[node]){
                if(vis[nei]==0){
                 int nd=d+1;
                if(nd<dist[nei]){
                    vis[nei]=1;
                    dist[nei]=nd;
                    q.push({dist[nei],nei});
                }
                }
           }
       }       
}
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
           vector<int>v1(n,INT_MAX);
           vector<int>v2(n,INT_MAX);
           vector<int>v3(n,INT_MAX);
           vector<vector<int>>adj(n+1);
           for(auto it:edges){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
           }
           func(x,v1,adj,n);
           func(y,v2,adj,n);
           func(z,v3,adj,n);
           int ans=0;
           for(int i=0;i<n;i++){
                vector<int>temp;
                temp.push_back(v1[i]);
                temp.push_back(v2[i]);
                temp.push_back(v3[i]);
                sort(temp.begin(),temp.end());
                int a=temp[0];
                int b=temp[1];
                int c=temp[2];
                if(((1LL*a*a)+(1LL*b*b))==(1LL*c*c)){
                      ans++;
                }
           }
           return ans;
    }
};