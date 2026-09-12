class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
         int n=nums.size();
         vector<int>pref(n);
         vector<int>suff(n);
         pref[0]=0;
         suff[n-1]=0;
         for(int i=1;i<n;i++){
              pref[i]=pref[i-1]+nums[i-1];
         }
         for(int i=n-2;i>=0;i--){
              suff[i]=suff[i+1]+nums[i+1];
         }
        //  for(auto it:pref){
        //      cout<<it<<' ';
        //  }
        //  cout<<endl;
        //  for(auto it:suff){
        //      cout<<it<<' ';
        //  }
         vector<int>ans(n);
         for(int i=0;i<n;i++){
              ans[i]=abs(pref[i]-suff[i]);
         }
         return ans;
    }
};