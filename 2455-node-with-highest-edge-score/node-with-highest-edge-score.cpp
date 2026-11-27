class Solution {
public:
    int edgeScore(vector<int>& edges) {
          map<int,long long>mp;
          for(int i=0;i<edges.size();i++){
               mp[edges[i]]+=i;
          }
          long long maxi=0;
          for(auto it:mp){
              maxi=max(maxi,(long long)it.second);
          }
          for(int i=0;i<edges.size();i++){
               if(mp[i]==maxi){
                    return i;
               }
          }
          return -1;
    }
};