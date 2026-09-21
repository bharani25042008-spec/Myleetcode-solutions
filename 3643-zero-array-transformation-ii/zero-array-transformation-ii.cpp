class Solution {
public:
bool func(vector<int>&nums,vector<vector<int>>&q,int k){
    int n=nums.size();
         vector<int>diff(n+1,0);
         for(int i=0;i<k;i++){
              int l=q[i][0];
              int r=q[i][1];
              int val=q[i][2];
              diff[l]+=val;
              if(r+1<n){
                 diff[r+1]-=val;
              }
         }
         int cur=0;
         for(int i=0;i<n;i++){
             cur+=diff[i];
             if(nums[i]-cur>0) return false;
         }
         return true;
}
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
          int n=q.size();
          int l=0;
          int r=n;
          int ans=-1;
          while(l<=r){
              int mid=(l+r)/2;
              if(func(nums,q,mid)){
                  ans=mid;
                  r=mid-1;
              }else{
                  l=mid+1;
              }
          }
          return ans;
    }
};