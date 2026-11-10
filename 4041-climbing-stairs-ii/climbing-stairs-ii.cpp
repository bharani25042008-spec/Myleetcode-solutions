class Solution {
public:
    

int func(int i,vector<int>&costs,int n,vector<int>&dp){
    if(i==n) return 0;

    if(dp[i]!=-1) return dp[i];

    int ans = INT_MAX;

    if(i+1<=n)
        ans=min(ans,costs[i]+1+func(i+1,costs,n,dp));

    if(i+2<=n)
        ans=min(ans,costs[i+1]+4+func(i+2,costs,n,dp));

    if(i+3<=n)
        ans=min(ans,costs[i+2]+9+func(i+3,costs,n,dp));

    return dp[i]=ans;
}
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        return func(0, costs, n,dp);
    }
};