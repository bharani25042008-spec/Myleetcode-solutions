class Solution {
public:
long long func(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        if(i<0||j<0) return 0;
        if(i>=grid.size()||j>=grid[0].size()){
              return 0;
        }
        if(grid[i][j]==0) return 0;
        if(vis[i][j]==1) return 0;
        vis[i][j]=1;
        long long l=func(i,j-1,grid,vis);
        long long r=func(i,j+1,grid,vis);
        long long d=func(i+1,j,grid,vis);
        long long u=func(i-1,j,grid,vis);
        return (long long)grid[i][j]+l+r+d+u;
}
    int countIslands(vector<vector<int>>& grid, int k) {
           int ans=0;
           int m=grid.size();
           int n=grid[0].size();
           vector<vector<int>>vis(m,vector<int>(n,0));
           for(int i=0;i<m;i++){
               for(int j=0;j<n;j++){
                   if(vis[i][j]==0&&grid[i][j]!=0){
                         long long val=func(i,j,grid,vis);
                         if(val%k==0) ans++;
                   }
               }
           }
           return ans;
    }
};