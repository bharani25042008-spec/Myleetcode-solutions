class Solution {
public:
bool func(int l,int r,int m,vector<int>&pref,vector<vector<int>>&dp){
     if(l==r){
         return true;
     }
     if(dp[l][r]!=-1) return dp[l][r];
    //  int sum=0;
    //  if(l==0){
    //     sum=pref[r];
    //  }else
    //  sum=pref[r]-pref[l-1];
    //  if(sum>=m){
    //      return true;
    //  }else{
    //      return false;
    //  } 
     for(int k=l;k<r;k++){ 
          int  leftsum=0;
          if(l==0){
             leftsum=pref[k];
          }else{
            leftsum=pref[k]-pref[l-1];
          }
          int rightsum=0;
          if(k+1==0){
            rightsum=pref[k+1];
          }else{
            rightsum=pref[r]-pref[k];
          }
          bool leftgood=(l==k||leftsum>=m);
          bool rightgood=(k+1==r||rightsum>=m);
          if(leftgood&&rightgood){
          bool left=func(l,k,m,pref,dp);
          bool right=func(k+1,r,m,pref,dp);
          if(left&&right){
           return  dp[l][r]=true;
          }
     }
     }
     return dp[l][r]=false;
}
    bool canSplitArray(vector<int>& nums, int m) {
          int n=nums.size();
          vector<int>pref(n);
          pref[0]=nums[0];
          for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
          }
          vector<vector<int>>dp(n,vector<int>(n+1,-1));
          return func(0,nums.size()-1,m,pref,dp);
    }
};