class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        set<int>st;
        for(auto it:edges){
              st.insert(it[1]);
        }
        for(int i=0;i<n;i++){
               if(st.find(i)==st.end()) ans.push_back(i);
        }
        return ans;
    }
};