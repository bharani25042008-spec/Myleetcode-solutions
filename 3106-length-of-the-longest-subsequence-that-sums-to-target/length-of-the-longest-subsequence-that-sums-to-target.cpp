class Solution {
public:
int func(int i,vector<int>&nums,int tar,vector<vector<int>>&dp){
    if(tar==0) return 0;
    if(i==nums.size()){
          return -1e9;
    }
    if(dp[i][tar]!=-1) return dp[i][tar];
    if(tar<0) return -1e9;
    int nt=func(i+1,nums,tar,dp);
    int take=-1e9;
    if(nums[i]<=tar){
         take=1+func(i+1,nums,tar-nums[i],dp);
    }
    return dp[i][tar]=max(take,nt);
}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
         vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
         int val= func(0,nums,target,dp);
         if(val<0) return -1;
         return val; 
    }
};