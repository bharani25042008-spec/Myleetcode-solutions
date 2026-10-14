class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //tomorrow is CIA and i didn't studied anything else and i had more fever i can't even look at the screen 
        //though this qns was asked at google today and i am just glad to solve this in one go....
        //umm can i go
          queue<pair<string,int>>q;
          q.push({beginWord,0});
          set<string>st;
          st.insert(beginWord);
          string a="abcdefghijklmnopqrstuvwxyz";
          set<string>vis(wordList.begin(),wordList.end());
          while(!q.empty()){
                auto[s,d]=q.front();
                q.pop();
                if(s==endWord){
                      return d+1;
                }
                for(int i=0;i<s.length();i++){
                      char temp=s[i];
                      for(int j=0;j<26;j++){
                         s[i]=a[j];
                         if(st.find(s)==st.end()&&vis.find(s)!=vis.end()){
                               q.push({s,d+1});
                               st.insert(s);
                         }
                   }
                   s[i]=temp;
                } 
          }
          return 0;
    }
};