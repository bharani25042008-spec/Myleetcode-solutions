class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>pref(n);
        pref[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]%2==0&&nums[i-1]%2==0){
                  pref[i]=pref[i-1]+1;
            }else if(nums[i]%2==1&&nums[i-1]%2==1){
                  pref[i]=pref[i-1]+1;
            }else{
                  pref[i]=pref[i-1];
            }
        }
        for(auto it:pref){
              cout<<it<<' ';
        }
        vector<bool>ans;
        for(auto it:queries){
             int l=it[0];
             int r=it[1];
             if((pref[r]-pref[l])>0){ 
                 ans.push_back(false);
             }else{
                 ans.push_back(true);
             }
        }
        return ans;
    }
};