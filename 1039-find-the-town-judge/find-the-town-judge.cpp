class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
           for(int i=1;i<=n;i++){
                set<pair<int,int>>st;
                bool ok=true;
                for(int j=0;j<trust.size();j++){
                      if(trust[j][0]==i){
                          ok=false;
                           break;
                      }else{
                           if(trust[j][1]==i){
                               st.insert({i,trust[j][0]});
                           }
                      }
                }
                if(ok){
                if(st.size()==n-1) return i;
                }
           }
           return -1;
    }
};