class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>>q;
        set<string>st(deadends.begin(),deadends.end());
        if(st.count("0000")) return -1;//edge yenna namma starting position eh deadend ah irundha we can't go anywhere just return -1;
        //genetic mutation and word ladder pattern with the same bfs idea just adding +1 and -1 are the costs of the state
        //yet 0-1 bfs intuition was a nightmare for me :(
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
                 s[i]=temp;//this line is the most important guy as he is the parent for the rest of his child 
                 // i need more grid dp and digit dp problems to solve the bfs if hell as boring and tough in the way of intuiton  how the competitive programmers are able to crack the convex hull with the ease still trying but it is tough though
                 //let's go and solve some dp problems and gain some confidence 
              }
        }
        return -1;
    }
};