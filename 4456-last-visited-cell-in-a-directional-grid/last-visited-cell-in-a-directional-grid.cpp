class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
          vector<int>ans;
          set<pair<int,int>>st;
          st.insert({0,0});
          int m=grid.size();
          int n=grid[0].size();
          int i=0;
          int j=0;
          while(true){
              char c=grid[i][j];
              if(c=='R'){
                   if(j+1>=n){
                      return {i,j};
                   }else{
                     if(st.find({i,j+1})!=st.end()){
                           return {i,j};
                     }
                      j+=1;
                      st.insert({i,j});
                   }
              }
              else if(c=='L'){
                   if(j-1<0){
                       return {i,j};
                   }else{
                      if(st.find({i,j-1})!=st.end()){
                            return {i,j};
                      }else{
                          j-=1;
                          st.insert({i,j});
                      }
                      
                   }
              }else if(c=='U'){
                  if(i-1<0){
                      return {i,j};
                  }else
                  {
                      if(st.find({i-1,j})!=st.end()){
                           return {i,j};
                      }else{
                           i-=1;
                           st.insert({i,j});
                      }
                  }
              }
              else if(c=='D'){
                    if(i+1>=m){
                          return {i,j};
                    }else{
                        if(st.find({i+1,j})!=st.end()){
                              return {i,j};
                        }else{
                             i+=1;
                             st.insert({i,j});
                        }
                    }
              }
          }
          return {0,0};
    }
};