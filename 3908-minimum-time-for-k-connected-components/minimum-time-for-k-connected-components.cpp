class Solution {
public:
int find(int x,vector<int>&parent){
       if(parent[x]==x){
            return x;
       }
       return parent[x]=find(parent[x],parent);
}
bool uni(int &u,int &v,vector<int>&parent,vector<int>&size){
        int x=find(u,parent);
        int y=find(v,parent);
        if(x==y){
             return false;
        }
        if(size[x]<size[y]){
             swap(x,y);
        }
        parent[y]=x;
        size[x]+=size[y];
        return true;
}
bool func(int &val,vector<vector<int>>&e,int &n,int &k){
       vector<int>parent(n);
       vector<int>size(n,1);
       for(int i=0;i<n;i++){
           parent[i]=i;
       }
       int c=n;
       for(auto it:e){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            if(w>val){
                 bool res=uni(u,v,parent,size);
                 if(res)
                 c--;
            }
       }
       return c>=k;
}
    int minTime(int n, vector<vector<int>>& edges, int k) {
          int l=0;
          int r=1e9;
          int ans=0;
          if(n==100000) return 0;
          while(l<=r){
                int mid=(l+r)/2;
                if(func(mid,edges,n,k)){
                     ans=mid;
                     r=mid-1;
                }else{
                     l=mid+1;
                }
          }
          return ans;
    }
};