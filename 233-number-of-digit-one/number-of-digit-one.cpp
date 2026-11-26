class Solution {
public:
int dp[17][2][10];
int func(string &s,int idx,int tight,int c){
      if(idx==s.length()){
            return c;
      }
      int up=0;
      if(tight){
          up=s[idx]-'0';
      }else{
          up=9;
      }
      int ans=0;
      if(dp[idx][tight][c]!=-1) return dp[idx][tight][c];
      for(int i=0;i<=up;i++){
          int newtight=(tight)&&(i==up);
          if(i==1){
              ans+=func(s,idx+1,newtight,c+1);
          }else{
              ans+=func(s,idx+1,newtight,c);
          }
      }
      return dp[idx][tight][c]=ans;
}
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string s=to_string(n);
        return func(s,0,1,0);
    }
};