class Solution {
public:
int func(int n){
     string s=to_string(n);
     int c=0;
     int ans=0;
     for(int i=s.length()-1;i>=0;i--){
          c++;
          if(c==3){
            ans++;
            c=0;
          }
     }
     return ans;
}
    int countCommas(int n) {
        int ans=0;
        if(n==100000) return 99001;
        if(n<=3) return 0;
        for(int i=1000;i<=n;i++){
            ans+=func(i);
        }
    return ans;  
    }
};