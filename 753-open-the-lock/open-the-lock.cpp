class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>>q;
        set<string>st(deadends.begin(),deadends.end());
        if(st.count("0000")) return -1;
        q.push({"0000",0});
        st.insert("0000");
        while(!q.empty()){
              auto [s,dist]=q.front();
              q.pop();
              if(s==target){
                  return dist;
              }
              for(int i=0;i<4;i++){
                char temp=s[i];
                 s[i]=(((s[i]-'0')+1)%10)+'0';
                 if(!st.count(s)){
                    st.insert(s);
                    q.push({s,dist+1});;
                 }
                 s[i]=temp;
                 s[i]=((((s[i]-'0')-1)+10)%10)+'0';
                 if(!st.count(s)){
                 st.insert(s);
                 q.push({s,dist+1});
                 }
                 s[i]=temp;
              }
        }
        return -1;
    }
};