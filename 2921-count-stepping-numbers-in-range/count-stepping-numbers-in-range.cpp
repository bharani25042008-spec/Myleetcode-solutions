class Solution {
public:
int dp[100][2][2][10];
const int MOD=1e9+7;
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
int func(string &s,int idx,bool tight,bool start,int prev){
      if(idx==s.length()){
             return 1;
      }
      int up=0;
      if(tight){
         up=s[idx]-'0';
      }else{
         up=9;
      }
      int ans=0;
      if(dp[idx][tight][start][prev]!=-1) return dp[idx][tight][start][prev];
      for(int i=0;i<=up;i++){
        bool newtight=(tight)&&(i==up);
        bool newstart=(start)||(i!=0);
        if(!newstart&&i==0){
               ans=(ans+func(s,idx+1,newtight,newstart,prev))%MOD;
        }else if(!start){
               ans=(ans+func(s,idx+1,newtight,newstart,i))%MOD;
        }else{
              if(abs(prev-i)>1) continue;
              if(abs(prev-i)==1){
              ans=(ans+func(s,idx+1,newtight,newstart,i))%MOD;
              }
        }
      }
      return dp[idx][tight][start][prev]=ans%MOD;
}
    int countSteppingNumbers(string low, string high) {
        
        low=f(low);
        memset(dp,-1,sizeof(dp));
        int val1=func(low,0,1,0,0);
        memset(dp,-1,sizeof(dp));
        int val2=func(high,0,1,0,0);
        
        return (val2-val1+MOD)%MOD;
    }
};