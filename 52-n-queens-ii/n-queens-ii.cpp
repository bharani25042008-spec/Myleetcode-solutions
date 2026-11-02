class Solution {
public:
set<vector<string>>st;
bool check(int i,int j,int n,vector<string>&s)
{
      int dr=i;
      int dc=j;
      while(j-1>=0){
           j--;
           if(s[i][j]=='Q') return false;
      }
      i=dr;
      j=dc;
      while(i-1>=0&&j-1>=0){
           j--;
           i--;
           if(s[i][j]=='Q') return false;
      }
      i=dr;
      j=dc;
      while(i+1<n&&j-1>=0){
           i++;
           j--;
           if(s[i][j]=='Q') return false;
      }
      return true;
}
void func(int col,vector<string>&s,int n){
      if(col==n){
          st.insert(s);
          return;
      }
      for(int i=0;i<n;i++){
          if(check(i,col,n,s)){
           s[i][col]='Q';
           func(col+1,s,n);
           s[i][col]='.';
          }
      }
}
    int totalNQueens(int n) {
            vector<string>ans(n);
            string temp(n,'.');
            for(int i=0;i<n;i++){
                   ans[i]=temp;
            }
            func(0,ans,n);
            for(auto it:st){
                  for(auto i:it){
                      cout<<i<<' ';
                  }
                  cout<<endl;
            }
            return st.size();
    }
};