class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
          set<int>st;
          for(int i=0;i<s.length();i++){
              if(s[i]=='0'){
                  st.insert(i);
              }
          }
          queue<int>q;
          int n=s.length();
        //   vector<int>vis(n,0);
        //   vis[0]=1;
          q.push(0);
          while(!q.empty()){
               int i=q.front();
               q.pop();
               if(i==n-1){
                 return true;
               }
               int left=i+minJump;
               int right=min(n-1,i+maxJump);
               auto it=st.lower_bound(left);
               while(it!=st.end()&&*it<=right){
                    q.push(*it);
                    it=st.erase(it);
               }
          }
          return false;
    }
};