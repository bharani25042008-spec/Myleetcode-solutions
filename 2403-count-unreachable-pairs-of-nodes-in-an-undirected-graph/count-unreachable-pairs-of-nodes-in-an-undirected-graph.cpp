class Solution {
public:
vector<int>parent;
vector<int>size;
int find(int x)
{
      if(parent[x]==x){
            return x;
      }
      return parent[x]=find(parent[x]);
}
void uni(int u,int v){
      int x=find(u);
      int y=find(v);
      if(x==y) return;
      if(size[x]<size[y]){
         swap(x,y);
      }
      parent[y]=x;
      size[x]+=size[y];
}
    long long countPairs(int n, vector<vector<int>>& edges) {
           long long ans=0;
           parent.resize(n);
           size.resize(n,1);
           for(int i=0;i<n;i++){
                parent[i]=i;
           }
           for(auto it:edges){
               int u=it[0];
               int v=it[1];
               if(find(u)!=find(v)){
                   uni(u,v);
               }
           }
           for(int i=0;i<n;i++){
               int p=find(i);
               cout<<p<<endl;
               ans+=(n-size[p]);
               cout<<ans<<' ';
           }
           return ans/2;
    }
};