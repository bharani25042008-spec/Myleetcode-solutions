class Solution {
public:
bool check(int i,int j,vector<string>&ans,int n){
         int dr=i;
         int dc=j;
         while(j-1>=0){
              j--;
              if(ans[i][j]=='Q') return false;
         }
         i=dr;
         j=dc;
         while(i-1>=0&&j-1>=0){
              i--;
              j--;
              if(ans[i][j]=='Q') return false;
         }
         i=dr;
         j=dc;
         while(i+1<n&&j-1>=0){
             i++;
             j--;
             if(ans[i][j]=='Q') return false;
         }
         return true;
}
void func(int col,vector<string>&s,int n,vector<vector<string>>&ans){
       if(col==n){
            ans.push_back(s);
            return;
       }
       for(int i=0;i<n;i++){
           if(check(i,col,s,n)){
               s[i][col]='Q';
               func(col+1,s,n,ans);
               s[i][col]='.';
           }
       }
}
    vector<vector<string>> solveNQueens(int n) {
           vector<vector<string>>ans;
           vector<string>s(n);
           string temp(n,'.');
           for(int i=0;i<n;i++){
                s[i]=temp;
           }
            func(0,s,n,ans);
            return ans;
    }
};