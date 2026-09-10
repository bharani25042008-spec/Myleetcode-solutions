class Solution {
public:
long  long dp[17][2][2][100][100];
int c1(int idx,int n){
     if(idx%2==0){
          return n;
     }
     return 0;
}
int c2(int idx,int n){
     if(idx%2==1){
         return n;
     }
     return 0;
}
long long func(string &s,int idx,bool tight,bool start,long long e,long long o,int cnt){
      if(idx==s.length()){
          if(cnt>=2){
            if(e==o) return 1;
           else return 0;
          }
          return 0;
      }
      int up=0;
      if(tight){
         up=s[idx]-'0';
      }else{
         up=9;
      }
      if(dp[idx][tight][start][e][o]!=-1) return dp[idx][tight][start][e][o];
      long long ans=0;
      for(int i=0;i<=up;i++){
           bool newtight=(tight)&&(i==up);
           bool newstart=(start)||(i!=0);
           if(!newstart&&i==0){
             ans+=func(s,idx+1,newtight,newstart,e,o,cnt);
           }else{
             ans+=func(s,idx+1,newtight,newstart,e+c1(idx,i),o+c2(idx,i),cnt+1);
           }
      }
      return dp[idx][tight][start][e][o]=ans;
}
    long long countBalanced(long long low, long long high) {
        low-=1;
        string s1=to_string(low);
        string s2=to_string(high);
        memset(dp,-1,sizeof(dp));
        long long val1=func(s1,0,1,0,0,0,0);
        memset(dp,-1,sizeof(dp));
        long long val2=func(s2,0,1,0,0,0,0);
        return val2-val1;
    }
};