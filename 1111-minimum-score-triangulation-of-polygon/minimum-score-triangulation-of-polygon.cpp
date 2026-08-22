class Solution {
public:
int func(int l,int r,vector<int>nums,vector<vector<int>>&dp){
      if(r-l+1<3){
         return 0;
      }
      int ans=INT_MAX;
      if(dp[l][r]!=-1){
         return dp[l][r];
      }
      for(int k=l+1;k<r;k++){
        int lp=func(l,k,nums,dp);
        int rp=func(k,r,nums,dp);
        int cost=nums[l]*nums[k]*nums[r];
        ans=min(ans,lp+rp+cost);
      }
      return dp[l][r]= ans;
}
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>>dp(values.size(),vector<int>(values.size(),-1));
          return func(0,values.size()-1,values,dp);
    }
};
