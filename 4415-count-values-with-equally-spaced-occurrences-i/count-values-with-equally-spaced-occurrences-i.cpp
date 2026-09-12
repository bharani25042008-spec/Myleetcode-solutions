class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
          map<int,vector<int>>mp;
          for(int i=0;i<nums.size();i++)
          { 
             mp[nums[i]].push_back(i);
          }
          int c=0;
          for(auto it:mp){
             vector<int>ans=it.second;
             if(ans.size()==3){
             if((ans[1]-ans[0])==(ans[2]-ans[1])){
                  c++;
             }
             }
          }
          return c;
    }
};