class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts,
                     vector<vector<int>>& dig) {
        int c = 0;
        set<vector<int>> st;
        for (int i = 0; i < dig.size(); i++) {
            st.insert(dig[i]);
        }
        for (int i = 0; i < artifacts.size(); i++) {
            vector<int> ans = artifacts[i];
            int r1 = ans[0];
            int r2 = ans[1];
            int r3 = ans[2];
            int r4 = ans[3];
            bool ok = true;
            //   if(st.find({r1,r2})==st.end()){
            //     ok=false;
            //   }
            //   if(st.find({r2,r3})==st.end()){
            //     ok=false;
            //   }
            //   if(st.find({r3,r4})==st.end()){
            //     ok=false;
            //   }
            //   if(st.find({r1,r4})==st.end()){
            //     ok=false;
            //   }
            //   if(st.find({r3,r2})==st.end()){
            //     ok=false;
            //   }
            for (int row = r1; row <= r3; row++) {
                for (int col = r2; col <= r4; col++) {

                    if (st.find({row, col}) == st.end()) {
                        ok = false;
                    }
                }
            }
            if (ok)
                c++;
        }
        return c;
    }
};