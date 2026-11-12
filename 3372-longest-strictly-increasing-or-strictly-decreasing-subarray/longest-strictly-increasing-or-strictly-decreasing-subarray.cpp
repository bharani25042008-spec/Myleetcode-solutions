class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
          int mx1=1;
          int mx2=1;
          int c1=1;
          int c2=1;
          for(int i=0;i<nums.size()-1;i++){
               if(nums[i]<nums[i+1]){
                  c1++;
                  mx1=max(mx1,c1);
               }else{
                  c1=1;
               }
          }
          for(int i=0;i<nums.size()-1;i++){
               if(nums[i]>nums[i+1]){
                   c2++;
                   mx2=max(mx2,c2);
               }else{
                   c2=1;
               }
          }
          return  max(mx1,mx2);
    }
};