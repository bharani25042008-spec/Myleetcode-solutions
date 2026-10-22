class Solution {
public:
int c1(int id,vector<int>&a){
        int ans=a.size();
        int l=0;
        int r=a.size()-1;
        while(l<=r){ 
              int mid=(l+r)/2;
            //   if(mid==id) continue;
              if(a[mid]>(0.5*a[id]+7)){
                    ans=mid;
                    r=mid-1;
              }else{
                    l=mid+1;
              }
        }
        return ans;
}
int c2(int id,vector<int>&a){
        int ans=-1;
        int l=0;
        int r=a.size()-1;
        while(l<=r){ 
              int mid=(l+r)/2;
            //   if(mid==id) continue;
              if(a[mid]<=a[id]){
                    ans=mid;
                    l=mid+1;
              }else{
                    r=mid-1;
              }
        }
        return ans;
}
    int numFriendRequests(vector<int>& ages) {
             int ans=0;
             sort(ages.begin(),ages.end());
             for(int i=0;i<ages.size();i++){
                   int val1=c1(i,ages);
                   int val2=c2(i,ages);
                   if(val2>=val1)
                      ans+=(val2-val1);
             }
             return ans;
    }
};