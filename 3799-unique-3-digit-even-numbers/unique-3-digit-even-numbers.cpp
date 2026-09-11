class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int>st;
        for(int i=0;i<digits.size();i++){
            if(digits[i]==0) continue;
             for(int j=0;j<digits.size();j++){
                 if(i==j) continue;
                  for(int k=0;k<digits.size();k++){
                     if(j==k||k==i) continue;
                      int val=(digits[i]*100)+(digits[j]*10)+(digits[k]);
                      cout<<val<<' ';
                      if(val%2==0){
                         st.insert(val);
                      }
                  }
             }
        }
        return st.size();
    }
};