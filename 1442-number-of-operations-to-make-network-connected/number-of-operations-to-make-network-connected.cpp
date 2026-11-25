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
      if(x==y){
          return;
      }
      if(size[x]<size[y]){
          swap(x,y);
      }
      parent[y]=x;
      size[x]+=size[y];
}
    int makeConnected(int n, vector<vector<int>>& connections) {
             parent.resize(n);
             size.assign(n,1);
             for(int i=0;i<n;i++){
                  parent[i]=i;
             }
             int components=n;
             int e=0;
             for(auto it:connections){
                   int u=it[0];
                   int v=it[1];
                   if(find(u)==find(v)){
                        e++;
                   }else{
                       components--;
                       uni(u,v);
                   }
             }
             if(e>=components-1){
                  return components-1;
             }
             return -1;
    }
};