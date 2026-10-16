class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
          //brute force adipoma
           vector<vector<int>>ans;
           set<vector<int>>st;
           sort(nums.begin(),nums.end());
          for(int i=0;i<nums.size();i++){
               int j=i+1;
               int k=nums.size()-1;
               while(j<k){
                  int sum=nums[i]+nums[j]+nums[k];
                  if(sum==0){
                      st.insert({nums[i],nums[j],nums[k]});
                      j++;
                      k--;
                  }else if(sum<0){
                       j++;
                  }else{
                       k--;
                  }
               }
          }
          for(auto it:st){
               ans.push_back(it);
          }
          return ans;
    }
};