class Solution {
public:
int func(int xr,int i,int j,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
       if(i>=grid.size()||j>=grid[0].size()) return 1e9;
       if(i<0||j<0) return 1e9;
       xr^=grid[i][j];
       if(dp[i][j][xr]!=-1) return dp[i][j][xr];
       if(i==grid.size()-1&&j==grid[0].size()-1) return xr;
       int right=func(xr,i,j+1,grid,dp);
       int down=func(xr,i+1,j,grid,dp);
       return dp[i][j][xr]=min(right,down);
}
    int minCost(vector<vector<int>>& grid) {
      int m=grid.size();
      int n=grid[0].size();
      vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(1032,-1)));
      return func(0,0,0,grid,dp);
    }
};