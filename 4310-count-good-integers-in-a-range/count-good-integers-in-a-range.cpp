class Solution {
public:
long long dp[18][2][2][10];
long long func(string &s,int idx,bool tight,bool start,int prev,int k){
      if(idx==s.length()){
          return 1;
      }
      int up=0;
      if(tight){
        up=s[idx]-'0';
      }else{
        up=9;
      }
      long long ans=0;
      if(dp[idx][tight][start][prev]!=-1){
         return dp[idx][tight][start][prev];
      }
      for(int i=0;i<=up;i++){
         bool newtight=(tight)&&(i==up);
         bool newstart=(start)||(i!=0);
         if(!newstart&&i==0){
             ans+=func(s,idx+1,newtight,newstart,prev,k);
         }else if(!start){
             ans+=func(s,idx+1,newtight,newstart,i,k);
         }else{
             if(abs(prev-i)>k){
                 continue;
             }else{
                 ans+=func(s,idx+1,newtight,newstart,i,k);
             }
         }
      }
      return dp[idx][tight][start][prev]=ans;
}
    long long goodIntegers(long long l, long long r, int k) {
          l-=1;
          string s1=to_string(l);
          string s2=to_string(r);
          memset(dp,-1,sizeof(dp));
          long long val1=func(s1,0,1,0,0,k);
          memset(dp,-1,sizeof(dp));
          long long val2=func(s2,0,1,0,0,k);
          return val2-val1;
    }
};