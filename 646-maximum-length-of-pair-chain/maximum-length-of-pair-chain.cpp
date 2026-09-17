class Solution {
public:
int func(int i,int prev,vector<vector<int>>&grid,vector<vector<int>>&dp){
       if(i==grid.size()){
             return 0;
       }
       if(dp[i][prev+1]!=-1) return dp[i][prev+1];
       int nottake=func(i+1,prev,grid,dp);
       int take=0;
       if(prev==-1||grid[prev][1]<grid[i][0]){
           take=1+func(i+1,i,grid,dp);
       }
       return dp[i][prev+1]=max(take,nottake);
}
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return func(0,-1,pairs,dp);
    }
};