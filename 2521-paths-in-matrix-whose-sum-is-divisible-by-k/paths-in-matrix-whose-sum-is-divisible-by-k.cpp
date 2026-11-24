class Solution {
public:
const int mod=1e9+7;
int func(int i,int j,int r,vector<vector<int>>&grid,int k,int m,int n,vector<vector<vector<int>>>&dp){
         if(i>=m||j>=n) return 0;
         if(i<0||j<0) return 0;
         r=((r+grid[i][j])%k)%mod;
         if(i==m-1&&j==n-1){
              return r==0;
         }
         if(dp[i][j][r]!=-1) return dp[i][j][r];
         int right=func(i,j+1,r,grid,k,m,n,dp)%mod;
         int down=func(i+1,j,r,grid,k,m,n,dp)%mod;
         return dp[i][j][r]=(right+down)%mod;

}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
          int m=grid.size();
          int n=grid[0].size();
          vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
          return func(0,0,0,grid,k,m,n,dp)%mod;
    }
};