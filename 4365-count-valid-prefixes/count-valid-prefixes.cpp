class Solution {
public:
    int countValidPrefixes(string s) {
          int c1=0;
          int c2=0;
          int ans=0;
          for(int i=0;i<s.length();i++){
                if(s[i]=='0'){
                       c1++;
                }else
                {
                       c2++;
                }
                if(abs(c1-c2)<=1) ans++;
          }
          return ans;
    }
};