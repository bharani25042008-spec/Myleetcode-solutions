class Solution {
public:
int dp[25][2][401];
const int mod=1e9+7;
string f(string s){
      int i=s.length()-1;
      while(i>=0){
           if(s[i]>'0'){
                s[i]--;
                break;
           }else{
               s[i]='9';
               i--;
      }
      }
      i=0;
      while(i+1<s.length()&&s[i]=='0'){
         i++;
      }
      return s.substr(i);
      
}
int func(string &s,int idx,bool tight,int sum,int mx,int mn){
      if(idx==s.length()){
          if(sum>=mn&&sum<=mx){
                return 1;
          }else{
                return 0;
          }
      }
      if(dp[idx][tight][sum]!=-1) return dp[idx][tight][sum];
      int up=0;
      if(tight){
           up=s[idx]-'0';
      }else{
           up=9;
      }
      int ans=0;
      for(int i=0;i<=up;i++){
           bool  newtight=(tight)&&(i==up);
           ans=(ans+func(s,idx+1,newtight,sum+i,mx,mn))%mod;
      }
      return dp[idx][tight][sum]=ans%mod;
}
    int count(string num1, string num2, int min_sum, int max_sum) {
          num1=f(num1);
          memset(dp,-1,sizeof(dp));
          int val1=func(num1,0,1,0,max_sum,min_sum);
          memset(dp,-1,sizeof(dp));
          int val2=func(num2,0,1,0,max_sum,min_sum);
          return (val2-val1+mod)%mod;
    }
};