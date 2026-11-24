class Solution {
public:
int func(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
       if(i<0||j<0) return 0;
       if(i>=grid.size()||j>=grid[0].size()){
           return 0;
       }
       int l=0;
       if(dp[i][j]!=-1) return dp[i][j];
       if(j-1>=0){
         if(grid[i][j-1]>grid[i][j]){
             l=1+func(i,j-1,grid,dp);
         }
       }
       int r=0;
       if(j+1<grid[0].size()){
          if(grid[i][j+1]>grid[i][j]){
             r=1+func(i,j+1,grid,dp);
          }
       }
       int u=0;
       if(i-1>=0){
          if(grid[i-1][j]>grid[i][j]){
            u=1+func(i-1,j,grid,dp);
          }
       }
       int d=0;
       if(i+1<grid.size()){
         if(grid[i+1][j]>grid[i][j]){
             d=1+func(i+1,j,grid,dp);
         }
       }
       return dp[i][j]=max({l,r,d,u});
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
           int maxi=0;
           int m=matrix.size();
           int n=matrix[0].size();
           vector<vector<int>>dp(m,vector<int>(n,-1));
           for(int i=0;i<matrix.size();i++){
             for(int j=0;j<matrix[0].size();j++){
                   maxi=max(maxi,func(i,j,matrix,dp));
             }
           }
           return maxi+1;
    }
};