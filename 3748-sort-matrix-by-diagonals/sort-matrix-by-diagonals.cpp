class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
          map<int,vector<int>>row;
          map<int,vector<int>>col;
          int m=grid.size();
          int n=grid[0].size();
          int st=0;
          for(int i=1;i<n;i++){
                vector<int>t;
                int r=st;
                int c=i;
                while(r<m&&c<n){
                      t.push_back(grid[r][c]);
                      r++;
                      c++;
                }
                row[i]=t;
          }
          for(int i=0;i<m;i++){
                vector<int>t;
                int r=i;
                int c=st;
                while(r<m&&c<n){
                      t.push_back(grid[r][c]);
                      r++;
                      c++;
                }
                col[i]=t;
          }
          for(int i=1;i<n;i++){
               vector<int>t=row[i];
               sort(t.begin(),t.end());
               int r=st;
               int c=i;
               int id=0;
               while(r<m&&c<n){
                   grid[r][c]=t[id++];
                   r++;
                   c++;
               }       
          }
          for(int i=0;i<m;i++){
               vector<int>t=col[i];
               sort(t.begin(),t.end(),greater<int>());
               int r=i;
               int c=st;
               int id=0;
               while(r<m&&c<n){
                  grid[r][c]=t[id++];
                  r++;
                  c++;
               }
          }
          return grid;
    }
};