class Solution {
public:
    bool canAliceWin(int n) {
         int val=10;
         if(n==10) return true;
         if(n<val) return false;
         int c=0;
         while(n>=val){
            n-=val;
            val--;
            c++;
         }
         if(c%2==1&&n<val) return true;
         return false;
    }
};