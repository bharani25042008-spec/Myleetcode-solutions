class Solution {
public:
int func(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,bool &c){
      if(i<0||j<0) return 0;
      if(i>=grid.size()||j>=grid[0].size()) return 0;
      if(grid[i][j]==1) return 0;
      if(vis[i][j]==1) return 0;
      if(i==grid.size()-1||j==grid[0].size()-1||i==0||j==0) c=false;
      
      vis[i][j]=1;
      int l=0;
      if(j-1>=0&&grid[i][j-1]==0)
         l=func(i,j-1,grid,vis,c);
      int r=0;
      if(j+1<grid[0].size()&&grid[i][j+1]==0)
         r=func(i,j+1,grid,vis,c);
      int u=0;
      if(i-1>=0&&grid[i-1][j]==0)
         u=func(i-1,j,grid,vis,c);
      int d=0;
      if(i+1<grid.size()&&grid[i+1][j]==0)
          d=func(i+1,j,grid,vis,c);
      return 1+l+r+d+u;
}
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int  i=0;i<m;i++){
              for(int j=0;j<n;j++){
                  if(vis[i][j]==0&&grid[i][j]==0){
                       bool c=true;
                       int val=func(i,j,grid,vis,c);
                       if(val>0&&c) ans++;
                  }
              }
        }
        return ans;
    }
};