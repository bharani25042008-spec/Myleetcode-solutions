class Solution {
public:
bool func(vector<int>&v,vector<int>&t){
         int c1=count(v.begin(),v.end(),1);
         int  c2=count(t.begin(),t.end(),1);
         return c1==1&&c2==1;
}
    int numSpecial(vector<vector<int>>& mat) {
          map<int,vector<int>>mp;
          int c=0;
          int cnt=0;
          for(int j=0;j<mat[0].size();j++){
                 vector<int>temp;
                  cnt=j;
                 for(int i=0;i<mat.size();i++){
                        temp.push_back(mat[i][j]);
                 }
                  mp[cnt]=temp;
                  cnt=0;
          }
          for(int i=0;i<mat.size();i++){
               for(int j=0;j<mat[0].size();j++){
                   if(mat[i][j]==1){
                        if(func(mat[i],mp[j])) c++;
                   }
               }
          }
    return c;
          
    }
};