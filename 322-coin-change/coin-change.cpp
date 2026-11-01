class Solution {
public:
int func(int i,vector<int>coins,int tar,vector<vector<int>>&dp){
          if(i==coins.size()-1){
               if(tar%coins[i]==0){
                    return tar/coins[i];
               }else{
                    return 1e9;
               }
          }
          if(dp[i][tar]!=-1) return dp[i][tar];
          int nottake=func(i+1,coins,tar,dp);
          int  take=1e9;
          if(coins[i]<=tar){
               take=1+func(i,coins,tar-coins[i],dp);
          }
          return dp[i][tar]=min(take,nottake);
}
    int coinChange(vector<int>& coins, int amount) {
           vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
           int val=func(0,coins,amount,dp);
           if(val>=1e9) return -1;
           return val;
    }
};