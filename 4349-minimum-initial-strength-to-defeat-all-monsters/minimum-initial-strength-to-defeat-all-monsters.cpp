class Solution {
public:
bool func(long long ans,vector<int>&m,vector<long long>&d){
          for(int i=0;i<m.size();i++){
               if(ans<0){
                   ans=0;
               }
               if(ans+d[i]>=m[i]){
                     ans-=m[i];
               }
               else{
                   return false;
               }
          }
          return true;
}
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        vector<long long>diff(n,0);
        for(auto it:boosts){
              int l=it[0];
              int r=it[1];
              int val=it[2];
              diff[l]+=val;
              if(r+1<n){
                 diff[r+1]-=val;
              }
        }
         for(int i=1;i<n;i++){
                  diff[i]=diff[i]+diff[i-1];
          }
          long long l=0;
          long long r=1e15;
          long long ans=0;
          while(l<=r){
               long long mid=l+(r-l)/2;
               if(func(mid,monsters,diff)){
                    ans=mid;
                    r=mid-1;
               }else{
                    l=mid+1;
               }
          }
          return ans;
    }
};