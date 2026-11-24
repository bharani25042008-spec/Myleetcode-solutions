#include<numeric>
class Solution {
public:
const int mod=1e9+7;
bool func(vector<long long>&arr){
       long long pro=1;
       long long l=arr[0];
       long long g=arr[0];
       for(auto it:arr){
           pro=(1LL*pro*it)%mod;
       }
       for(int i=1;i<arr.size();i++){
           g=gcd(g,arr[i]);
           l=std::lcm(l,arr[i]);
       }
       return pro==(g*l);
}
    int maxLength(vector<int>& nums) {

          int maxi=0;
          for(int i=0;i<nums.size();i++)
          {
              vector<long long>temp;
              for(int j=i;j<nums.size();j++){
                   temp.push_back((long long)nums[j]);
                   if(func(temp)){
                      maxi=max(maxi,j-i+1);
                   }
              }
          }
          return maxi;
    }
};