class Solution {
public:
vector<int>parent,size;
//it's DSU
int find(int x){
       if(parent[x]==x){
           return x;
       }
       return parent[x]=find(parent[x]);
}
void u(int a,int b){
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
    int findCircleNum(vector<vector<int>>& isConnected) {
         int n=isConnected.size();
         vector<vector<int>>adj;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                  if(i!=j&&isConnected[i][j]==1){
                      adj.push_back({i,j});
                  }
            }
         }
         parent.resize(n);
         size.resize(n,1);
         for(int i=0;i<n;i++){
              parent[i]=i;
         }
         int ans=n;
         for(auto it:adj){
               if(find(it[0])!=find(it[1])){
                   u(it[0],it[1]);
                   ans--;
               }
         }
         return ans;
    }
};