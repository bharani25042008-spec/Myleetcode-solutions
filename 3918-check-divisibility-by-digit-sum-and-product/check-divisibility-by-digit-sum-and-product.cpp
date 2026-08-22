class Solution {
public:
    bool checkDivisibility(int n) {
        string s=to_string(n);
        int sum=0;
        int p=1;
        for(auto it:s){
             sum+=it-'0';
             p*=it-'0';
        }
        return n%(sum+p)==0;
    }
};