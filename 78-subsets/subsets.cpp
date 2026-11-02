class Solution {
public:
void func(int i,vector<int>&v,vector<vector<int>>&ans,vector<int>&res){
      if(i==v.size()){
           ans.push_back(res);
           return;
      }
      res.push_back(v[i]);
      func(i+1,v,ans,res);
      res.pop_back();
      func(i+1,v,ans,res);
}
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>>ans;
         vector<int>res;
         func(0,nums,ans,res);
         return ans;
    }
};