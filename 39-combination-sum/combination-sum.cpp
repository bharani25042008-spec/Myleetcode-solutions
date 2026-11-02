class Solution {
public:
void func(int i,vector<int>&v,int tar,vector<vector<int>>&ans,vector<int>&res){
        if(tar==0){
               ans.push_back(res);
               return;
        }
        if(i==v.size()-1){
               int val=0;
               if(tar%v[i]==0){
                   val=tar/v[i];
                for(int j=0;j<val;j++){
                    res.push_back(v[i]);
               }
               ans.push_back(res);
               for(int j=0;j<val;j++){
                   res.pop_back();
               }
               }
             return;
        }
        func(i+1,v,tar,ans,res);
        int t=0;
        if(v[i]<=tar){
               res.push_back(v[i]);
               func(i,v,tar-v[i],ans,res);
               res.pop_back();
        }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>>ans;
            vector<int>res;
            func(0,candidates,target,ans,res);
            return ans;
    }
};