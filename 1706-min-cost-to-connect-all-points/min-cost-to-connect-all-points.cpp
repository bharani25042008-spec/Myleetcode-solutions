class Solution {
public:
vector<int>parent,size;
int find(int x){
      if(parent[x]==x){
          return x;
      }
      return parent[x]=find(parent[x]);
}
void uni(int a,int b){
       int x=find(a);
       int y=find(b);
       if(x==y) return;
       if(size[x]<size[y]){ 
          swap(x,y);
       }
       parent[y]=x;
       size[x]+=size[y];
}
    int minCostConnectPoints(vector<vector<int>>& points) {
           int n=points.size();
           int s=points.size();
           parent.resize(n);
           size.resize(n,1);
           for(int i=0;i<n;i++){
              parent[i]=i;
           }
           vector<vector<int>>adj;
           for(int i=0;i<n;i++){
              for(int j=i+1;j<n;j++){
                   adj.push_back({i,j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
              }
           }
           sort(adj.begin(),adj.end(),[](vector<int>&a,vector<int>&b){
               return a[2]<b[2];
           });
           int cost=0;
           int cnt=0;
           for(auto it:adj){
              int u=it[0];
              int v=it[1];
              int c=it[2];
              if(find(u)!=find(v)){
                  uni(u,v);
                  cost+=c;
                  cnt++;
                  if(cnt==s-1){
                       break;
                  }
              }
           }
           return cost;
    }
};