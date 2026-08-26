class Solution {
public:
const int mod=1e9+7;
//i love grid dp
int func(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
      if(i<0||j<0){
          return 0;
      }
      if(i>=grid.size()||j>=grid[0].size()){
          return 0;
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      int ans=1;
      if(i+1<grid.size()){
         if(grid[i+1][j]>grid[i][j]){
           
             ans=(ans+  func(i+1,j,grid,dp))%mod;
         }
      }
      if(i-1>=0){
         if(grid[i-1][j]>grid[i][j]){
             //ans++;
             ans=(ans+func(i-1,j,grid,dp))%mod;
         }
      }
      if(j+1<grid[0].size()){
        if(grid[i][j+1]>grid[i][j]){
           
             ans=(ans+func(i,j+1,grid,dp))%mod;
        }
      }
      if(j-1>=0){
        if(grid[i][j-1]>grid[i][j]){
             
            ans=(ans+ func(i,j-1,grid,dp))%mod;
        }
      }
      return dp[i][j]=ans%mod;
}
    int countPaths(vector<vector<int>>& grid) {
         int ans=0;
         vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                 ans=(ans+func(i,j,grid,dp))%mod;
            }
         }

         return ans%mod;
    }
};