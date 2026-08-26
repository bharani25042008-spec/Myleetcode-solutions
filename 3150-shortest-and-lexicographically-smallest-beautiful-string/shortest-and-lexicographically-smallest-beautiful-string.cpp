class Solution {
public:
bool func(string s,int k){
      int c=count(s.begin(),s.end(),'1');
      return c==k;
}
    string shortestBeautifulSubstring(string s, int k) {
          vector<string>ans;
          vector<string>res;
          for(int i=0;i<s.length();i++){
            string temp="";
            for(int j=i;j<s.length();j++){
                 temp+=s[j];
                 ans.push_back(temp);
            }
          }
          for(auto it:ans){
              if(func(it,k)){
                 res.push_back(it);
              }
          }
          sort(res.begin(),res.end(),[&](string a,string b){
              if(a.length()==b.length())
                   return a<b;
                return a.length()<b.length();
    });
          if(res.empty()) return "";
          return res.front();
    }
};