class Solution {
public:
    int heightChecker(vector<int>& heights) {
           vector<int>t=heights;
           sort(t.begin(),t.end());
           int c=0;
           for(int i=0;i<t.size();i++){
                 if(t[i]!=heights[i]) c++;
           }
           return c;
    }
};