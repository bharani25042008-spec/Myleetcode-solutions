class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // int c=0;
        // for(int i=0;i<arr1.size();i++){
        //       bool ok=true;
        //       for(int j=0;j<arr2.size();j++){
        //            if(abs(arr1[i]-arr2[j])<=d){
        //                 ok=false;
        //                 break;
        //            }
        //       }
        //       if(ok) c++;
        // }
        // return c;
        //a-b=c-->a>=b+c
        int ans=0;
         sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        for(auto it:arr1){
               int l=0;
               int r=arr2.size()-1;
               int res=-1;
               while(l<=r){
                   int mid=(l+r)/2;
                   if(arr2[mid]>=it-d){
                        res=mid;
                        r=mid-1;
                   }else{
                        l=mid+1;
                   }
               }
               if(res==-1||arr2[res]>it+d) ans++;
        }
        return ans;
    }
};