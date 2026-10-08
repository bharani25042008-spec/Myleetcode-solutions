class Solution {
public:
    bool isPathCrossing(string path) {
          set<pair<int,int>>st;
          st.insert({0,0});
          int i=0;
          int j=0;
          for(auto it:path){
                if(it=='N'){
                    i-=1;
                    if(st.find({i,j})!=st.end()){
                            return true;
                    }else{
                          st.insert({i,j});
                    }
                }else if(it=='E'){
                      j+=1;
                      if(st.find({i,j})!=st.end()){
                           return true;
                      }else{
                          st.insert({i,j});
                      }
                }else if(it=='W'){
                       j-=1;
                       if(st.find({i,j})!=st.end()){
                             return true;
                       }else{
                            st.insert({i,j});
                       }
                }else if(it=='S'){
                       i+=1;
                       if(st.find({i,j})!=st.end()){
                               return true;
                       }else{
                            st.insert({i,j});
                       }
                }
          }
          return false;
    }
};