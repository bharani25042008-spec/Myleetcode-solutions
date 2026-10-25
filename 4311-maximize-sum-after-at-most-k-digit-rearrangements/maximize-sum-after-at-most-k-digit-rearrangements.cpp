class Solution {
public:
    void func(string &s){
         sort(s.begin(),s.end(),greater<char>());
    }
    long long maximizeSum(vector<int>& nums, int k) {
         vector<pair<int,int>>p;
         for(int i=0;i<nums.size();i++){
               string s=to_string(nums[i]);
               func(s);
               int val=stoi(s);
               int g=0;
               if(val>nums[i]){
                   p.push_back({val-nums[i],nums[i]});
               }else{
                   p.push_back({nums[i]-val,nums[i]});
               }
         }
         long long  ans=0;
         sort(p.begin(),p.end());
         while(k--){
              ans+=p.back().first;
              ans+=p.back().second;
              p.pop_back();
         }
         for(auto it:p){
               ans+=it.second;
         }
        return ans;
    }
};