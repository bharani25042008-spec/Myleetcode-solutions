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
      size[x]+=size[y];
      parent[y]=x;
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++){
              parent[i]=i;
        }
         for(auto it:edges){
               int u=it[0];
               int v=it[1];
               if(find(u)==find(v)){
                  return {u,v};
               }
               uni(u,v);
         }
         return {0,0};
    }
};