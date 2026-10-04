class Solution {
public:
    bool checkValidString(string s) {
        int l=0;
        int h=0;
        for(auto it:s){
              if(it=='('){
                   l++;
                   h++;
              }else if(it==')'){
                    l--;
                    h--;
              }else{
                   l--;
                   h++;
              }
              if(h<0) return false;
              l=max(0,l);
        }
        return l==0;
    }
};