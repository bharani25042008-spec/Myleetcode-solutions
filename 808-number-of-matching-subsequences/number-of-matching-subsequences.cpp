class Solution {
public:
bool func(string &s,string &t){
       int i=0;
       int j=0;
       while(i<s.length()&&j<t.length()){
          if(s[i]==t[j]){
              i++;
              j++;
          }else{
              i++;
          }
       }
       return j==t.length();
}
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto it:words){
              if(mp.find(it)!=mp.end()){
                  mp[it]++;
              }
              else{
                  if(func(s,it)){
                     mp[it]++;
                  }
              }
        }
        int ans=0;
        for(auto it:mp){
           ans+=it.second;
        }
        return ans;
    }
};