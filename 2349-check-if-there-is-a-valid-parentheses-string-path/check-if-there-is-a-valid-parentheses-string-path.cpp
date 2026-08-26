class Solution {
public:
const int mod=1e9+7;
long long func(long long i,long long j,vector<vector<char>>&grid,long long score,vector<vector<vector<long long>>>&dp){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()){
               return 0;
        }
        if(grid[i][j]=='('){
            score++;
        }
        if(grid[i][j]==')'){
            score--;
        }
        if(score<0){
             return 0;
        }
        if(i==grid.size()-1&&j==grid[0].size()-1){
              if(score==0){
                 return 1;
              }else{
                 return 0;
              }
        }
        if(dp[i][j][score]!=-1){
             return dp[i][j][score];
        }
        long long d=func(i+1,j,grid,score,dp);
        long long r=func(i,j+1,grid,score,dp);
        return dp[i][j][score]=(d+r)%mod;
}
    bool hasValidPath(vector<vector<char>>& grid) {
          vector<vector<vector<long long >>>dp(grid.size(),vector<vector<long long>>(grid[0].size(),vector<long long>(300,-1)));
          long long val= func(0,0,grid,0,dp);
          return val>0;
    }
};