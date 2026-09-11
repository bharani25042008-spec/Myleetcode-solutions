class Solution {
public:
int func(int i,int j,string &s,string &t,int &m,int &n,vector<vector<int>>&dp){
      if(i>=m||j>=n){
           return 0;
      }
      if(s[i]==t[j]){
         return dp[i][j]=1+func(i+1,j+1,s,t,m,n,dp);
      }
      if(dp[i][j]!=-1) return dp[i][j];
      int first=func(i+1,j,s,t,m,n,dp);
      int sec=func(i,j+1,s,t,m,n,dp);
      return dp[i][j]= max(first,sec);
}
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(0,0,text1,text2,m,n,dp);
    }
};