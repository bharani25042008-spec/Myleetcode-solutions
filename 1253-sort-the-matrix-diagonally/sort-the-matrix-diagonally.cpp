class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int,vector<int>>row;
        map<int,vector<int>>col;
        int n=mat.size();
        int m=mat[0].size();
        int st=0;
        for(int i=0;i<m;i++){
             int r=st;
             int c=i;
             vector<int>t;
             while(r<n&&c<m){
                   t.push_back(mat[r][c]);
                   r++;
                   c++;
             }
             row[i]=t;
        }
        for(int i=1;i<n;i++){
             int r=i;
             int c=st;
             vector<int>t;
             while(r<n&&c<m){
                   t.push_back(mat[r][c]);
                    r++;
                    c++;
             }
             col[i]=t;
        }
        for(int i=0;i<m;i++){
            vector<int>t=row[i];
            int r=st;
            int c=i;
            sort(t.begin(),t.end());
            int id=0;
             while(r<n&&c<m){
                   mat[r][c]=t[id++];
                   r++;
                   c++;
             }
        }
         for(int i=1;i<n;i++){
            vector<int>t=col[i];
            int r=i;
            int c=st;
            sort(t.begin(),t.end());
            int id=0;
             while(r<n&&c<m){
                   mat[r][c]=t[id++];
                   r++;
                   c++;
             }
        }
        return mat;
    }
};