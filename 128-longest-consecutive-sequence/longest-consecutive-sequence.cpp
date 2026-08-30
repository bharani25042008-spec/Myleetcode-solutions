class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         int c=1;
         int maxi=1;
         sort(nums.begin(),nums.end());
         if(nums.empty()) return 0;
         for(int i=0;i<nums.size()-1;i++){
             if((nums[i]+1)==nums[i+1]){
                 c++;
                 maxi=max(maxi,c);
             }else  if(nums[i]==nums[i+1]){
                   continue;
                }else{
                c=1;
             }
         }
         return maxi;
    }
};