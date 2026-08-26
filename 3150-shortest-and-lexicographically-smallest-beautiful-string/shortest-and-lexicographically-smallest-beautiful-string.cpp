class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
            int l=0;
            int c=0;
            vector<string>ans;
            for(int i=0;i<s.length();i++){
                 if(s[i]=='1'){
                     c++;
                 }
                 while(c>k){
                     if(s[l]=='1'){
                         c--;
                     }
                     l++;
                 }
                 if(c==k){
                    while(s[l]=='0'){
                        l++;
                    }
                     ans.push_back(s.substr(l,i-l+1));
                 }
            }
            sort(ans.begin(),ans.end(),[&](string a,string b){
                  if(a.length()==b.length())
                      return a<b;
                   return a.length()<b.length();
            });
          if(ans.empty()) return "";
          return ans.front();
    }
};