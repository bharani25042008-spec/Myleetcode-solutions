class Solution {
public:
bool func(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='I'||c=='O'||c=='E'||c=='U';
}
    bool isValid(string word) {
        if(word.length()<3) return false;
        int v=0;
        int c=0;
        for(auto it:word){
            if(!isalnum(it)){
                  return false;
            }else{
              if(func(it)){
                  v++;
              }else if(isalpha(it)){
                  c++;
              }
        }
        }
        return v>=1&&c>=1;
    }
};