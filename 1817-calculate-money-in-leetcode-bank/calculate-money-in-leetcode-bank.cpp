class Solution {
public:
    int totalMoney(int n) {
          int c=0;
          if(n>=7){
          int rem=n/7;
          int t=rem;
          int ans=0;
          while(rem--){
               for(int i=1;i<=7;i++){
                   ans+=(i+c);
               } 
               c++;
          }
          int r=7*t;
          int rem2=n-r;

          for(int i=1;i<=rem2;i++){
                 ans+=(i+c);
          }
          return ans;
          }else{
              int ans=0;
              for(int i=1;i<=n;i++){
                   ans+=i;
              }
              return ans;
          }
          return 0;
    }
};