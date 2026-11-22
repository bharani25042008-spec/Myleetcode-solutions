class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
          map<int,int>mp;
          for(auto it:roads){
             mp[it[0]]++;
             mp[it[1]]++;
          }
          set<vector<int>>st;
          for(auto it:roads){
               sort(it.begin(),it.end());
               st.insert(it);
          }
          int maxi=0;
          for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                  if(i==j) continue;
                  else{
                      int val=mp[i]+mp[j];
                      vector<int>v={i,j};
                      sort(v.begin(),v.end());
                      if(st.find(v)!=st.end()){
                          val-=1;
                      }
                      maxi=max(maxi,val);
                  }
             }
          }
        return maxi;
    }
};