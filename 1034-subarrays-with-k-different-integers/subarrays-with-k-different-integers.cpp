class Solution {
public:
int func(vector<int>&nums,int k){
       map<int,int>mp;
       int l=0;
       int ans=0;
       int c=0;
       for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==1) c++;
            while(c>k){
                 mp[nums[l]]--;
                 if(mp[nums[l]]==0){
                      mp.erase(nums[l]);
                      c--;
                 }
                 l++;
            }
            ans+=i-l+1;
       }
       return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};