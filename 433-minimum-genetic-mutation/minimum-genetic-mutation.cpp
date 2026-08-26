class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
          set<string>st(bank.begin(),bank.end());
          set<string>vis;
          queue<pair<string,int>>q;
          q.push({startGene,0});
          vis.insert(startGene);
          string s="ACGT";
          while(!q.empty()){
            auto[str,dist]=q.front();
            q.pop();
            if(str==endGene){
                return dist;
            }
            for(int i=0;i<8;i++){
                 char temp=str[i];
                 for(int j=0;j<s.length();j++){
                      str[i]=s[j];
                      if(st.count(str)&&!vis.count(str)){
                        vis.insert(str);
                        q.push({str,dist+1});
                      }
                 }
                 str[i]=temp;
            }
          }
          return -1;
    }
};