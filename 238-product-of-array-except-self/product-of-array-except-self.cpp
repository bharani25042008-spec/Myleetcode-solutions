class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
           int pro=1;
           int n=nums.size();
           vector<int>pref(n);
           for(int i=1;i<n;i++){
                pro*=nums[i-1];
                pref[i]=pro;
           }
           int suff=1;
           for(int i=n-2;i>=0;i--){
                 suff*=nums[i+1];
                 pref[i]*=suff;
           }
           int prd=1;
           for(int i=1;i<n;i++){
               prd*=nums[i];
           }
           pref[0]=prd;
           return pref;
    }
};