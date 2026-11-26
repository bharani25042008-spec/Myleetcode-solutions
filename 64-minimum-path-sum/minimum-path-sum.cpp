class Solution {
public:
int func(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
       if(i>=grid.size()||j>=grid[0].size()||i<0||j<0)
       {
            return 1e9;
       }
       if(dp[i][j]!=-1) return dp[i][j];
       if(i==grid.size()-1&&j==grid[0].size()-1){
           return grid[i][j];
       }
       int right=func(i,j+1,grid,dp);
       int down=func(i+1,j,grid,dp);
       return dp[i][j]=grid[i][j]+min(right,down);
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(0,0,grid,dp);
    }
};