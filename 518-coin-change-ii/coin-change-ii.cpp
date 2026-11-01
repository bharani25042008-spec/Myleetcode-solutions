class Solution {
public:
int func(int i,vector<int>&coins,int tar,vector<vector<int>>&dp){
       if(i==coins.size()-1){
            return tar%coins[i]==0;
       }
       if(tar==0){
           return 1;
       }
       if(dp[i][tar]!=-1) return dp[i][tar];
       int nt=func(i+1,coins,tar,dp);
       int t=0;
       if(coins[i]<=tar){
           t=func(i,coins,tar-coins[i],dp);
       }
       return dp[i][tar]=nt+t;
}
    int change(int amount, vector<int>& coins) {
          vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
          int val=func(0,coins,amount,dp);
          return val;
    }
};