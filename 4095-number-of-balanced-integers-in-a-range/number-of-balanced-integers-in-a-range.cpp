class Solution {
public:
long long dp[17][2][2][100][100];
int c1(int id,int n){
        if(id%2==1){
             return n;
        }
        return 0;
}
int c2(int id,int i)
{
      if(id%2==0){
           return i;
      }
      return 0;
}
long long func(string &s,int idx,bool tight,bool start,int c,int o,int e){
       if(idx==s.length()){
            if(c>=2&&o==e){
                   return 1;
            }
            else{
                   return 0;
            }
       }
       if(dp[idx][tight][start][o][e]!=-1) return dp[idx][tight][start][o][e];
       int up=0;
       if(tight){
            up=s[idx]-'0';
       }else{
            up=9;
       }
       long long ans=0;
       for(int i=0;i<=up;i++){
            bool newtight=(tight)&&(i==up);
            bool newstart=(start)||(i!=0);
            if(!newstart&&i==0){
                ans+=func(s,idx+1,newtight,newstart,c,o,e);
             }
            // else if(!start){
            //     ans+=func(s,idx+1,newtight,newstart,c,o,e);
            // }
            else{
                ans+=func(s,idx+1,newtight,newstart,c+1,o+c1(idx,i),e+c2(idx,i));
            }
       }
       return dp[idx][tight][start][o][e]=ans;
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