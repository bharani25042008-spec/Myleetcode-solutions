class Solution {
public:
int func(int s,int c,int n){
      if(s==n){
         return 0;
      }
      int copy=1e9;
      int paste=1e9;
      if(s>n) return 1e9;
      if(s!=c){
         copy=1+func(s,s,n);
      }
      if(c>0){
         paste=1+func(s+c,c,n);
      }
      return min(copy,paste);
}
    int minSteps(int n) {
         //just recursion thaaana
         //ok enaku two possiblity iruku
         //onnu ellathaium copy pannuven
         //innonu ellathaium paste pannuven but both costs 1 
         if(n==1) return 0;
         return func(1,0,n);
    }
};