class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;int cnt=1;

        for(auto it:s){
              if(it=='('){
                   cnt++;
              }else if(it==')'){
                    cnt--;
                    maxi=max(maxi,cnt);
              }
        }
        return maxi;
    }
};