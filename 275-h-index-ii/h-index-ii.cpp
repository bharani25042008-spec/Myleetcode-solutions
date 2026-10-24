class Solution {
public:
int func(int i,vector<int>&nums){
       int l=0;
       int r=nums.size()-1;
       int ans=-1;
       while(l<=r){
          int mid=(l+r)/2;
          if(nums[mid]>=i){
               ans=mid;
               r=mid-1;
          }else{
               l=mid+1;
          }
       }
       return ans;
}
    int hIndex(vector<int>& citations) {
          int maxi=0;
          for(int i=0;i<=1000;i++){
               int ans=func(i,citations);
               if(ans!=-1){
               if(i<(citations.size()-ans+1)){
                    maxi=max(maxi,i);
               }
               }
          }
          return maxi;

    }
};