class Solution {
public:
const int mod=1e9+7;
int func(int i,int j,vector<vector<int>>&grid,int dir,vector<vector<vector<int>>>&dp){
         if(i<0||j<0) return 0;
         if(i>=grid.size()||j>=grid[0].size()) return 0;
         if(i==grid.size()-1&&j==grid[0].size()-1){
                return 1;
         }
         int r=0;
         int d=0;
         if(dp[i][j][dir]!=-1) return dp[i][j][dir];
         if(grid[i][j]==1){
              if(dir==0){
                  d=func(i,j+1,grid,1,dp);
              }else{
                  r=func(i+1,j,grid,0,dp);
              }
         }
         else{
             d=func(i+1,j,grid,0,dp);
             r=func(i,j+1,grid,1,dp);
         }
         return dp[i][j][dir]=(d+r)%mod;
}
    int uniquePaths(vector<vector<int>>& grid) {
           int m=grid.size();
           int n=grid[0].size();
           vector<vector<vector<int>>>dp1(m,vector<vector<int>>(n,vector<int>(2,-1)));
           vector<vector<vector<int>>>dp2(m,vector<vector<int>>(n,vector<int>(2,-1)));
           //0 for down
           //1 for right
           int val1=func(0,0,grid,0,dp1);
           int val2=func(0,0,grid,1,dp2);
           return (val1+val2)/2;
    }
};