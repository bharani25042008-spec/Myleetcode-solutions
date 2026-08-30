class Solution {
public:
    string reverseWords(string s) {
        string it;
        stringstream ss(s);
        vector<string>ans;
        while(ss>>it){
             ans.push_back(it);
        }
        reverse(ans.begin(),ans.end());
        string res="";
        for(int i=0;i<ans.size();i++){
            res+=ans[i];
             if(i!=ans.size()-1){
                res+=" ";
             }
        }
        return res;
    }
};