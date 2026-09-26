class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
          unordered_map<string,string>mp;
          for(auto it:knowledge){
                mp[it[0]]=it[1];
          }
          int i=0;
          int n=s.length();
          string ans="";
          while(i<n){
              if(s[i]=='('){
                   int j=i+1;
                   string res="";
                   while(j<n&&s[j]!=')'){
                        res+=s[j];
                        j++;
                   }
                   if(mp.find(res)!=mp.end()){
                         ans+=mp[res];
                   }else{
                         ans+="?";
                   }
                   i=j+1;
              }
              else{
                  ans+=s[i];
                  i++;
              }
          }
          return ans;
    }
};