class Solution {
public:
    string removeOuterParentheses(string s) {
         stack<char>st;
         int start=0;
         string ans="";
         for(int i=0;i<s.length();i++){
                if(s[i]=='('){
                    if(st.empty()) start=i;
                     st.push('(');
                }else{
                     st.pop();
                     if(st.empty()){
                          string temp=s.substr(start,i-start+1);
                          temp.pop_back();
                          reverse(temp.begin(),temp.end());
                          temp.pop_back();
                          reverse(temp.begin(),temp.end());
                          ans+=temp;
                     }
                }
         }
         return ans;
    }
};