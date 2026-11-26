class Solution {
public:
int func(int i,int j,string &s,string &t,vector<vector<int>>&dp){
       if(i==s.length()||j==t.length()){
             return 0;
       }
       if(dp[i][j]!=-1) return dp[i][j];
       if(s[i]==t[j]){
           return dp[i][j]=1+func(i+1,j+1,s,t,dp);
       }else{
           return dp[i][j]=max(func(i+1,j,s,t,dp),func(i,j+1,s,t,dp));
       }
}
    int longestPalindromeSubseq(string s) {
           string temp=s;
           reverse(temp.begin(),temp.end());
           int n=s.length();
           vector<vector<int>>dp(n,vector<int>(n,-1));
           return func(0,0,s,temp,dp);
    }
};