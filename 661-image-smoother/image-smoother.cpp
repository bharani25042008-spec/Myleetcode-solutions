class Solution {
public:
int func(int i,int j,vector<vector<int>>&grid)
{
     //indha int for loop ellamae oru naal palan kodukum gra nambika than kedacha sandhosam illana payasam
     int c=0;
     int ans=0;
     if(i-1>=0){
         ans+=grid[i-1][j];
         c++;
     }
     if(j-1>=0){
        ans+=grid[i][j-1];
        c++;
     }
     if(i+1<grid.size()){
         ans+=grid[i+1][j];
         c++;
     }
     if(j+1<grid[0].size()){
         ans+=grid[i][j+1];
         c++;
     }
     if(i-1>=0&&j-1>=0){
         ans+=grid[i-1][j-1];
         c++;
     }
     if(i-1>=0&&j+1<grid[0].size()){
         ans+=grid[i-1][j+1];
         c++;
     }
     if(i+1<grid.size()&&j-1>=0){
         ans+=grid[i+1][j-1];
         c++;
     }
     if(i+1<grid.size()&&j+1<grid[0].size()){
         ans+=grid[i+1][j+1];
         c++;
     }
     ans+=grid[i][j];
     c++;
     return floor((ans/c));
}
    vector<vector<int>> imageSmoother(vector<vector<int>>& grid) {
          vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size()));
          for(int i=0;i<grid.size();i++){
              for(int j=0;j<grid[0].size();j++){
                   ans[i][j]=(func(i,j,grid));
              }
          }
          return ans;
    }
};