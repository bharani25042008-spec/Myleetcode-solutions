class Solution {
public:
int func(int i,vector<int>&nums,int tar){
       int l=i+1;
       int r=nums.size()-1;
       int ans=-1;
       while(l<=r)
       {
           int mid=(l+r)/2;
           if((nums[mid]+nums[i])<tar){
                ans=mid;
                l=mid+1;
           }else{
                r=mid-1;
           }
       }
       return ans;
}
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
               int val=func(i,nums,target);
               if(val!=-1){
                    ans+=(val-i);
               }
        }
        return ans;
    }
};