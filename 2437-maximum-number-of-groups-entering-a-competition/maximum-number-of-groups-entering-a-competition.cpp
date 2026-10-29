class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        //3 5 6 7 10 12
        int n=grades.size();
        int l=1;
        int r=n;
        int ans=0;
        while(l<=r){
              long long mid=l+(r-l)/2;
              long long k=(mid*(mid+1)/2);
              if(k<=n){
                  ans=mid;
                  l=mid+1;
              }else{
                  r=mid-1;
              }
        }
    return ans;
    }
};