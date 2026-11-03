class Solution {
public:
    int minMoves(vector<int>& nums) {
          int maxi=*max_element(nums.begin(),nums.end());
          int ans=0;
          for(auto it:nums){
               ans+=abs(it-maxi);
          }
          return ans;
    }
};