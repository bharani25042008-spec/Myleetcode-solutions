class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        //my hands are shivering as today i just saw my peak
           set<int>st(nums.begin(),nums.end());
           vector<vector<int>>ans;
           vector<int>temp;
           for(int i=lower;i<=upper;i++){
                if(st.find(i)==st.end()){
                        temp.push_back(i);
                }else{
                      if(!temp.empty()){
                           ans.push_back({temp.front(),temp.back()});
                           temp.clear();
                      }
                }
           }
           if(!temp.empty()){
                 ans.push_back({temp.front(),temp.back()});
           }
           return ans;
    }
};