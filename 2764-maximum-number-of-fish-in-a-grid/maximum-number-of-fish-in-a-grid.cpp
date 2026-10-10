class Solution {
public:
int func(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>&grid)
{
       if(i<0||j<0) return 0;
       if(i>=grid.size()||j>=grid[0].size()) return 0;
       if(grid[i][j]==0) return 0;
       if(vis[i][j]) return 0;
       vis[i][j]=true;
       int l=func(i,j-1,vis,grid);
       int r=func(i,j+1,vis,grid);
       int d=func(i+1,j,vis,grid);
       int u=func(i-1,j,vis,grid);
       return grid[i][j]+(l+r+d+u);

}
    int findMaxFish(vector<vector<int>>& grid) {
          int m=grid.size();
          int n=grid[0].size();
          vector<vector<bool>>vis(m,vector<bool>(n,false));
          int ans=0;
          for(int i=0;i<m;i++){
              for(int j=0;j<n;j++){
                   if(grid[i][j]>0&&!vis[i][j]){
                         ans=max(ans,func(i,j,vis,grid));
                   }
              }
          }
          return ans;
    }
};