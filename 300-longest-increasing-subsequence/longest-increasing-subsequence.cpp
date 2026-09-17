class Solution {
public:
int func(int i,int prev,vector<int>&nums,vector<vector<int>>&dp){
      if(i==nums.size()){
          return 0;
      }
      if(dp[i][prev+1]!=-1) return dp[i][prev+1];
      int nottake=func(i+1,prev,nums,dp);
      int take=0;
      
      if(prev==-1||nums[i]>nums[prev]){
         take=1+func(i+1,i,nums,dp);
      }
      return dp[i][prev+1]=max(nottake,take);
}
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(3000,-1));
        return func(0,-1,nums,dp);
    }
};