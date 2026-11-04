class Solution {
public:
int dp[11][2][2][1032];
int func(int idx,string &s,bool tight,bool start,int mask){
        if(idx==s.length()){
            return 1;
        }
        int up=0;
        if(tight){
              up=s[idx]-'0';
        }else{
              up=9;
        }
        if(dp[idx][tight][start][mask]!=-1) return dp[idx][tight][start][mask];
        int ans=0;
        for(int i=0;i<=up;i++){
               bool newtight=(tight)&&(i==up);
               bool newstart=(start)||(i!=0);
               if(!newstart&&i==0){
                     ans+=func(idx+1,s,newtight,newstart,mask);
               }else{
                    if(mask&(1<<i)) continue;
                    else{
                        ans+=func(idx+1,s,newtight,newstart,mask|(1<<i));
                    }
               }
        }
        return dp[idx][tight][start][mask]=ans;
}
    int countNumbersWithUniqueDigits(int n) {
           int l=pow(10,n)-1;
           string s=to_string(l);
           memset(dp,-1,sizeof(dp));
           int val=func(0,s,1,0,0);
           return val;
    }
};