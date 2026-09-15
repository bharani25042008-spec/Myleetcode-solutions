class Solution {
public:
void func(int i,vector<int>&nums,vector<int>&res,vector<vector<int>>&ans){
      if(i==nums.size()){
           ans.push_back(res);
           return;
      }
      res.push_back(nums[i]);
      func(i+1,nums,res,ans);
      res.pop_back();
      func(i+1,nums,res,ans);
}
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        func(0,nums,res,ans);
        for(auto it:ans){
            for(auto i:it) cout<<i<<' ';
            cout<<endl;
        }
        int val=0;
        for(auto it:ans){
            int sum=0;
            for(auto i:it){
                 sum^=i;
            }
            val+=sum;
        }
        return val;
    }
};