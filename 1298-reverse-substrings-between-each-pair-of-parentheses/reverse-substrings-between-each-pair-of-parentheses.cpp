class Solution {
public:
    string reverseParentheses(string s) {
        int  c=0;
        for(auto it:s){
              if(it=='(') c++;
        }
        string ans="";
        while(c>0){
            int cnt=0;
            int i=0;
            while(i<s.length()){
                if(s[i]=='('){
                      cnt++;
                      if(cnt==c){
                         int j=i+1;
                         string res="";
                         while(j<s.size()&&s[j]!=')')
                         {
                              res+=s[j];
                              j++;
                         }
                         c-=1;
                         reverse(res.begin(),res.end());
                         string temp1=s.substr(0,i);
                         string temp2=s.substr(j+1);
                         s=temp1+res+temp2;
                          break;
                      }
                }
                i++;
            }
        }
        return s;
    }
};