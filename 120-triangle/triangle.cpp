class Solution {
public:
int func(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
      if(i==grid.size()-1){
             return grid[i][j];
       }
       if(i>=grid.size()||j>=grid[i].size()){
             return 1e9;
       }
    
       if(dp[i][j]!=INT_MAX) return dp[i][j];
       
       int firstmove=func(i+1,j,grid,dp);
       int secondmove=func(i+1,j+1,grid,dp);
       return dp[i][j]=grid[i][j]+min(firstmove,secondmove);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,INT_MAX));
          return func(0,0,triangle,dp);
    }
};