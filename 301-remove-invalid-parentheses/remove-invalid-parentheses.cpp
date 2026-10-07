class Solution {
public:
void func(int i,int l,int r,int bal,string &cur,set<string>&st,string &s){
          if(i==s.size()){
              if(l==0&&r==0&&bal==0){
                   st.insert(cur);
              }
              return;
          }
          if(s[i]=='('){
                if(l>0){
                    l--;
                    func(i+1,l,r,bal,cur,st,s);
                    l++;
                }
                cur.push_back('(');
                func(i+1,l,r,bal+1,cur,st,s);
                cur.pop_back();
          }
          else if(s[i]==')'){
                if(r>0){
                      r--;
                      func(i+1,l,r,bal,cur,st,s);
                      r++;
                }
                if(bal>0){
                     cur.push_back(')');
                     func(i+1,l,r,bal-1,cur,st,s);
                     cur.pop_back();
                }
          }else{
               cur.push_back(s[i]);
               func(i+1,l,r,bal,cur,st,s);
               cur.pop_back();
          }
}
    vector<string> removeInvalidParentheses(string s) {
           vector<string>ans;
           set<string>st;
           int l=0;
           int r=0;
           int b=0;
           for(auto it:s){
              if(it=='('){
                    b++;
              }else if(it==')'){ 
                 if(b>0){
                     b--;
                 }else{
                     r++;
                 }
              }
           }
           l=b;
           string cur="";
           func(0,l,r,0,cur,st,s);
           for(auto it:st){
                  ans.push_back(it);
           }
           return ans;
    }
};