class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
          long long ans=0;
          long long n=nums.size();
          map<int,vector<int>>mp;
          for(int i=0;i<nums.size();i++){
                 string s=to_string(nums[i]);
                 for(int j=0;j<s.length();j++){
                        mp[j].push_back(s[j]-'0');
                 }
          }
          for(auto it:mp){
                vector<int>v=it.second;
                map<int,int>m;
                for(auto i:v){
                      m[i]++;
                }
                long long tot=0;
                for(auto i:m){
                      tot+=1LL*i.second*(n-i.second);
                }
                ans+=tot/2;
          }
          return ans;
    }
};