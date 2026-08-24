class Solution {
public:
int func(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp,int m,int n){
      if(i<0||j<0){
          return 0;
      }
      if(i>=m||j>=n){
          return 0;
      }
      if(i==m-1&&j==n-1){
            return 1;
      }
      if(grid[i][j]==1){
         return 0;
      }
      if(dp[i][j]!=-1){
            return dp[i][j];
      }
      int right=func(i,j+1,grid,dp,m,n);
      int down=func(i+1,j,grid,dp,m,n);
      return dp[i][j]=right+down;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1){
              return 0;
        }
        if(obstacleGrid[m-1][n-1]==1){
              return 0;
        }
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(0,0,obstacleGrid,dp,m,n);
    }
};