class Solution {
public:
int func(int n,vector<int>&mp){
         string s=to_string(n);
         for(int i=0;i<s.length();i++){
               s[i]=mp[s[i]-'0']+'0';
         }
         return stoi(s);
}
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
          vector<pair<int,pair<int,int>>>p;
          for(int i=0;i<nums.size();i++){
                int val=func(nums[i],mapping);
                p.push_back({nums[i],{val,i}});
          }
         sort(p.begin(),p.end(),[&](auto a,auto b){
               if(a.second.first==b.second.first){
                     return a.second.second<b.second.second;
               }
               return a.second.first<b.second.first;
         });
         vector<int>ans;
         for(auto it:p){
                ans.push_back(it.first);
         }
         return ans;
    }
};