class Solution {
public:
int func(int i,vector<int>&ans,int tar,vector<vector<int>>&dp){
       if(i==0){
            if(tar%ans[i]==0) return tar/ans[i];
            else return 1e9;
       }
       if(dp[i][tar]!=-1) return dp[i][tar];
       int nottake=func(i-1,ans,tar,dp);
       int take=1e9;
       if(ans[i]<=tar){
          take=1+func(i,ans,tar-ans[i],dp);
       }
       return dp[i][tar]=min(take,nottake);
       
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int val= func(n-1,coins,amount,dp);
        if(val>=1e9) return -1;
        return val;
    }
};