class Solution {
public:
// woah i think this was the first problem that i solved while learning digit dp
bool f(int n){
     return n==1;
}
int dp[11][2][11];
int func(string s,int idx,bool tight,int c){
      if(idx==s.length()){
         return c;
      }
      int up=0;
      if(tight){
         up=s[idx]-'0';
      }else{
        up=9;
      }
      if(dp[idx][tight][c]!=-1) return dp[idx][tight][c];
      int ans=0;
      for(int i=0;i<=up;i++){
         bool newtight=(tight)&&(i==up);
         ans+=func(s,idx+1,newtight,c+f(i));
      }
      return dp[idx][tight][c]=ans;
}
    int countDigitOne(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return func(s,0,1,0);
    }
};