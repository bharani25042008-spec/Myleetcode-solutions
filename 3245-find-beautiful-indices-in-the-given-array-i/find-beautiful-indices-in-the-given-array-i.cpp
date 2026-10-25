class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
          vector<int>ans;
          vector<int>p1;
          vector<int>p2;
          if (a.size() > s.size() || b.size() > s.size()) {
             return {};
          }
          for(int i=0;i<=s.length()-a.size();i++){
               string s1=s.substr(i,a.size());
               if(s1==a){
                    p1.push_back(i);
               }
          }
          for(int i=0;i<=s.length()-b.size();i++){
               string s1=s.substr(i,b.size());
               if(s1==b){
                    p2.push_back(i);
               }
          }
          for(int i=0;i<p1.size();i++){
              for(int j=0;j<p2.size();j++){
                   if(abs(p1[i]-p2[j])<=k){
                         ans.push_back(p1[i]);
                         break;
                   }
              }
          }
          return ans;
    }
};