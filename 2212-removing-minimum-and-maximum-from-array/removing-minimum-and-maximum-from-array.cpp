class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int fmin=0;
        int fmax=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==mini){
                fmin=i;
            }else if(nums[i]==maxi){
                fmax=i;
            }
        }
        int bmin=0;
        int bmax=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==maxi){
                bmax=i;
            }else if(nums[i]==mini){
                bmin=i;
            }
        }
        bmax=n-bmax;
        bmin=n-bmin;
    int ans=INT_MAX;
    ans=min(ans,max(fmin,fmax)+1);
    ans=min(ans,max(bmin,bmax));
    ans=min(ans,(fmin+bmax)+1);
    ans=min(ans,(fmax+bmin)+1);
    return ans;

    }
};