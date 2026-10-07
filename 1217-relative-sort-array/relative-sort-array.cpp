class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
           vector<int>ans;
           vector<int>rem;
           for(auto it:arr2){
                int c=count(arr1.begin(),arr1.end(),it);
                     while(c--){
                           ans.push_back(it);
                     }
           }
           set<int>st(arr2.begin(),arr2.end());
           for(auto it:arr1){
                if(st.find(it)==st.end()) rem.push_back(it);
           }
           sort(rem.begin(),rem.end());
           for(auto it:rem) ans.push_back(it);
           return ans;
    }
};