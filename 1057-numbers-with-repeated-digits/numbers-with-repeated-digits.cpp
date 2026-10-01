class Solution {
public:
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
       return ans;
}
    int numDupDigitsAtMostN(int n) {
        string s=to_string(n);
        int val=func(0,s,1,0,0);
        return n-val+1;
    }
};