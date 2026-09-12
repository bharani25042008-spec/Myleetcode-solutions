class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
         map<int,vector<int>>mp;
         for(int i=0;i<nums.size();i++){
             mp[nums[i]].push_back(i);
         }
        //  for(auto it:mp){
        //       for(auto i:it.second){
        //          cout<<i<<' ';
        //       }
        //       cout<<endl;
        //  }

         int c=0;
         for(auto it:mp){
             vector<int>ans=it.second;
             bool ok=true;
             if(ans.size()<3){
                 ok=false;
             }
             if(ans.size()>=3){
                 for(int i=0;i<ans.size()-2;i++){
                      int val1=ans[i+1]-ans[i];
                      int val2=ans[i+2]-ans[i+1];
                      if(val1!=val2){
                         ok=false;
                         break;
                      }
                 }
             }
             if(ok) c++;
         }
         return c;
    }
};