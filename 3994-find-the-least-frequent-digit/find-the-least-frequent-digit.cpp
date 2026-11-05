class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<char,int>mp;
        string s=to_string(n);
        for(auto it:s){
              mp[it]++;
        }
        int mini=INT_MAX;
        for(auto it:mp){
               mini=min(mini,it.second);
        }
        int ans=INT_MAX;
        for(auto it:mp){
              if(it.second==mini){
                  ans=min(ans,it.first-'0');
              }
        }
        return ans;
    }
};