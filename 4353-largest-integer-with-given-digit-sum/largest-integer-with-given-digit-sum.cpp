class Solution {
public:
bool func(int n,int sum){
     string s=to_string(n);
     int val=0;
     for(auto it:s){
         val+=it-'0';
     }
     return val==sum;
}
    int largestInteger(int n, int s) {
        int ans=INT_MIN;
        int l=pow(10,n)-1;
        for(int i=l;i>=0;i--){
             string temp=to_string(i);
             if(temp.length()<=n){
                 if(func(i,s)) return i;
             }
        }
        return -1;
    }
};