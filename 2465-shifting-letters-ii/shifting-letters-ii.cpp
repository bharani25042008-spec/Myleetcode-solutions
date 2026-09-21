class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
          int n=s.length();
          vector<int>diff(n+1,0);
          for(auto it:shifts){
              int l=it[0];
              int r=it[1];
              int val=0;
              if(it[2]==1){
                 val=1;
              }else{
                 val=-1;
              }
              diff[l]+=val;
              if(r+1<n){
                  diff[r+1]-=val;
              }
          }
          int cur=0;
          for(int i=0;i<n;i++){
            cur+=diff[i];
            int shift=(cur%26+26)%26;
            int pos=s[i]-'a';
            int c=(shift+pos)%26;
            s[i]=c+'a';
          }
          return s;
    }
};