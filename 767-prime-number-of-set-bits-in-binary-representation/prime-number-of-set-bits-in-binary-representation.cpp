class Solution {
public:
//it's a digit dp problem 
int dp[32][2][32];
string  func(int n){
    if (n == 0) return "0";
      string ans="";
      while(n>0){
          ans+=(n%2)+'0';
          n/=2;
      }
      reverse(ans.begin(),ans.end());
      return ans;
}
bool f(int n){
      if(n<2) return false;
      for(int i=2;i*i<=n;i++){
          if(n%i==0) return false;
      }
      return true;
}
int c(string &s,int idx,bool tight,int count){
       if(idx==s.length()){
          if(f(count)){
               return 1;
          }else{
               return 0;
          }
       }
       int up=0;
       if(tight){
          up=s[idx]-'0';
       }else{
          up=1;
       }
       if(dp[idx][tight][count]!=-1) return dp[idx][tight][count];
       int ans=0;
       for(int i=0;i<=up;i++){
          bool newtight=(tight)&&(i==up);
              if(i==1){
                ans+=c(s,idx+1,newtight,count+1);
              }else{
                ans+=c(s,idx+1,newtight,count);
              }
       }
       return dp[idx][tight][count]=ans;
}
    int countPrimeSetBits(int left, int right) {
          left-=1;
          string  n1=func(left);
          string  n2=func(right);
           memset(dp,-1,sizeof(dp));
          int val1=c(n1,0,1,0);
           memset(dp,-1,sizeof(dp));
          int val2=c(n2,0,1,0);
          return (val2-val1);
    }
};