class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
          set<char>st(allowed.begin(),allowed.end());
          int c=0;
          for(int i=0;i<words.size();i++){
                string s=words[i];
                bool ok=true;
                for(auto it:s){
                      if(st.find(it)==st.end()){
                           ok=false;
                           break;
                      }
                }
                if(ok) c++;
          }
          return c;
    }
};