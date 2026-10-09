class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
         set<int>st;
         int ans=0;
         for(int i=0;i<f.size();i++){
               bool ok=false;
            for(int j=0;j<b.size();j++){
                   if(f[i]<=b[j]){
                    if(st.find(j)==st.end()){
                            ok=true;
                            st.insert(j);
                            break;
                    }
                   }
            }
            if(!ok) ans++;
         }
         return ans;
    }
};