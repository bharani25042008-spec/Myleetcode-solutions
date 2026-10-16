class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           set<char>st;
           int l=0;
           int maxi=0;
           for(int i=0;i<s.length();i++){
                while(st.count(s[i])){
                       st.erase(s[l]);
                       l++;
                }
                st.insert(s[i]);
                maxi=max(maxi,i-l+1);
           }
           return maxi;
    }
};