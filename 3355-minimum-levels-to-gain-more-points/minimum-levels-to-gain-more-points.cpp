class Solution {
public:
    int minimumLevels(vector<int>&nums) {
        int n=nums.size();
        vector<int>pref(n,0);
        if(nums[0]==0){
              pref[0]=-1;
        }else{
             pref[0]=1;
        }
        for(int i=1;i<n;i++){
              int val=0;
              if(nums[i]==1){
                    val=1;
              }else{
                    val=-1;
              }
              pref[i]=pref[i-1]+val;
        }
        vector<int>suff(n,0);
        if(nums[n-1]==1){
               suff[n-1]=1;
        }else{
               suff[n-1]=-1;
          }
        for(int i=n-2;i>=0;i--){
            int val=0;
            if(nums[i]==1){
                  val=1;
            }else{
                  val=-1;
            }
            suff[i]=suff[i+1]+val;
        }
        int mini=INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
                if(pref[i]>suff[i+1]){
                    mini=min(mini,(i+1));
                }
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }
};