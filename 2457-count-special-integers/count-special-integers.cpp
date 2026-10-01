class Solution {
public:
int dp[18][2][2][1032];
//i think the 3D print might took morning 4 '0 clock to complete today's sleep was gone for someone who didn't even ask me whether u are ok
int func(string s,int idx,bool tight,bool start,int mask){
    if(idx==s.length()) return 1;
    int up=0;
    if(tight){
        up=s[idx]-'0';
    }else up=9;
    int ans=0;
    if(dp[idx][tight][start][mask]!=-1)  return dp[idx][tight][start][mask];
    for(int i=0;i<=up;i++){
          bool newtight=(tight)&&(i==up);
          bool newstart=(start)||(i!=0);
          if(!newstart&&i==0){
               ans+=func(s,idx+1,newtight,newstart,mask);
          }else{
             if(mask&(1<<i)) continue;
               ans+=func(s,idx+1,newtight,newstart,mask|(1<<i));
          }
    }
    return dp[idx][tight][start][mask]=ans;
}
    int countSpecialNumbers(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        int val=func(s,0,1,0,0);
        return val-1;
    }
};