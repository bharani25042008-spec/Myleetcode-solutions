class Solution {
public:
void func(int idx,vector<vector<int>>&ans){
      for(int i=0;i<ans.size();i++){
         for(int j=0;j<ans[i].size();j++){
             if(i==idx){
                 ans[i][j]++;
             }
         }
      }
}
void fun(int idx,vector<vector<int>>&ans){
      for(int i=0;i<ans.size();i++){
         for(int j=0;j<ans[i].size();j++){
             if(j==idx){
                 ans[i][j]++;
             }
         }
      }
}
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>>ans(m,vector<int>(n,0));
        set<int>st;
        set<int>stt;
        // for(auto it:indices)
        // {
        //       st.insert(it[0]);
        //       stt.insert(it[1]);
        // }
        // for(int i=0;i<m;i++){
        //      for(int j=0;j<n;j++){
        //          if(st.find(i)!=st.end()||stt.find(j)!=stt.end()){
        //               ans[i][j]=ans[i][j]+1;
        //          }
        //      }
        // }
        for(auto it:indices){
             func(it[0],ans);
             fun(it[1],ans);
        }
        int c=0;
        for(auto it:ans){
             for(auto i:it) cout<<i<<endl;
        }
        for(auto it:ans){
             for(auto i:it){
                 if(i%2==1) c++;
             }
        }
    return c;
    }
};