class Solution {
public:
//let's wait for oct 15 to see whether we would qualify for the icpc regionals or not
string func(int n){
       string s="";
       while(n>0){
             s+=(n%2)+'0';
             n/=2;
       }
       cout<<s;
       return s;
}
    bool isPalindromic(string s) {
         string ans="";
         for(auto it:s){
              int val=(it-'a')+97;
              string temp=func(val);
              while(temp.length()<8){
                    temp+='0';
              }
              reverse(temp.begin(),temp.end());
              ans+=temp;
         }
         string t=ans;
         reverse(t.begin(),t.end());
         cout<<ans;
         return t==ans;
    }
};