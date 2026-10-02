class Solution {
public:
bool c(string s){
      stack<char>st;
      for(auto it:s){
          if(it=='('){
              st.push(it);
          }else{
              if(st.empty()) return false;
              else if(it==')'&&st.top()=='(') st.pop();
              else return false;
          }
      }
      return st.empty();
}
void func(int i,string res,vector<string>&ans,int  &n){
        
        if(i==2*n){
              if(c(res)){
                   ans.push_back(res);
              }
              return;
        }
         res.push_back('(');
         func(i+1,res,ans,n);
         res.pop_back();
         res.push_back(')');
         func(i+1,res,ans,n);
         res.pop_back();
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string res="";
        string s="";
        func(0,res,ans,n);
        return ans;
    }
};