class Solution {
public:
int func(int i,vector<int>&nums,int low,int high){
        int l=i+1;
        int r=nums.size()-1;
        int ans=nums.size();
        while(l<=r){
              int mid=(l+r)/2;
              int sum=nums[i]+nums[mid];
              if(sum>=low){
                   ans=mid;
                   r=mid-1;
              }else{
                   l=mid+1;
              }
        }
        return ans;
}
int fun(int i,vector<int>&nums,int low,int high){
         int l=i+1;
         int r=nums.size()-1;
         int ans=-1;
         while(l<=r){
               int mid=(l+r)/2;
               int sum=nums[mid]+nums[i];
               if(sum<=high){ 
                    ans=mid;
                    l=mid+1;
               }else{
                    r=mid-1;
               }
         }
         return ans;
}
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
            sort(nums.begin(),nums.end());
            long long ans=0;
            for(int i=0;i<nums.size();i++){
                     int val1=func(i,nums,lower,upper);
                     int val2=fun(i,nums,lower,upper);
                     if(val2>=val1){
                           ans+=(val2-val1)+1;
                     }
            }
            return ans;
    }
};