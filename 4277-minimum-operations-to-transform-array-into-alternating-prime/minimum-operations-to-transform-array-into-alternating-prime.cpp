class Solution {
public:
int func(int val,vector<int>&p){
    int c=0;
        while(p[val]==0){
              val++;
              c++;
        }
        return c;
}
int fun(int val,vector<int>&p){
      int c=0;
      while(p[val]==1){
             val++;
             c++;
      }
      return c;
}
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int maxi=200000;
        vector<int>prime(maxi+1,1);
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i*i<=maxi;i++){
              if(prime[i]==1){
                  for(int j=i*i;j<=maxi;j+=i){
                      prime[j]=0;
                  }
              }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
               if(i%2==0){
                   if(prime[nums[i]]==1){
                       continue;
                   }else{
                       ans+=func(nums[i],prime);
                   }
               }else{
                   if(prime[nums[i]]==0){
                        continue;
                   }else{
                       ans+=fun(nums[i],prime);
                   }
               }
        }
    return ans;
    }
};