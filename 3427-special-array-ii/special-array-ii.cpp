class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
           int n=nums.size();
           vector<int>pref(n,0);
           pref[0]=1;
           vector<bool>ans;
           for(int i=1;i<nums.size();i++){
               if(nums[i]%2==0&&nums[i-1]%2==0){
                     pref[i]=pref[i-1]+1;
               }else if(nums[i]%2==1&&nums[i-1]%2==1){
                     pref[i]=pref[i-1]+1;
               }else{
                    pref[i]=pref[i-1];
               }
           }
           for(auto it:queries){
               int l=it[0];
               int r=it[1];
               int val=0;
               
               val=pref[r]-pref[l];
               
               if(val>0){
                    ans.push_back(false);
               }else{
                    ans.push_back(true);
               }
           }
           return ans;
    }
};