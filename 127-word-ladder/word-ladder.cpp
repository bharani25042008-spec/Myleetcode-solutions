class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        string str="abcdefghijklmnopqrstuvwxyz";
        queue<pair<string,int>>q;
        set<string>st(wordList.begin(),wordList.end());
        set<string>vis;
        vis.insert(beginWord);
        q.push({beginWord,0});
        while(!q.empty()){
            auto [s,dist]=q.front();
            q.pop();
            if(s==endWord){
                   return dist+1;
            }
            for(int i=0;i<s.length();i++){
                 char temp=s[i];
                 for(int j=0;j<26;j++){
                     s[i]=str[j];
                     if(st.count(s)&&!vis.count(s)){
                         vis.insert(s);
                         q.push({s,dist+1});
                     }
                 }
                 s[i]=temp;
            }
        }
        return 0;
    }
};