class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
          int ans=0;
          map<int,int>mp;
          for(int j=0;j<grid[0].size();j++){
              int c=0;
             for(int i=0;i<grid.size();i++){
                   if(grid[i][j]==1){
                       c++;
                   }
             }
             mp[j]=c;
          }
          for(auto it:mp){
               cout<<it.first<<' '<<it.second<<endl;
          }
          for(int i=0;i<grid.size();i++){
              for(int j=0;j<grid[0].size();j++){
                   if(grid[i][j]==1){
                       int c1=count(grid[i].begin(),grid[i].end(),1);
                       int c2=mp[j];
                       if(c1>1||c2>1) ans++;
                   }
              }
          }
          return ans;
    }
};