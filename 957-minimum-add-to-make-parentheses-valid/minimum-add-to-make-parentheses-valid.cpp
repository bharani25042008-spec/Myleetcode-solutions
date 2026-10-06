class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int c=0;
        for(auto it:s){
             if(it=='('){
                  st.push(it);
             }else{
                  if(!st.empty()&&it==')'&&st.top()=='('){
                       st.pop();
                  }else{
                       c++;
                  }
             }
        }
        return st.size()+c;
    }
};