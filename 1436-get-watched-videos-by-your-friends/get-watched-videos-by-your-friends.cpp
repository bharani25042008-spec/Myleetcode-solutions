class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
            queue<int>q;
            q.push(id);
            int n=watchedVideos.size();
            vector<int>vis(n,0);
            vis[id]=1;
            int l=0;
            while(!q.empty()){
                  vector<int>temp;
                  int s=q.size();
                  while(s--){
                  int node=q.front();
                  q.pop();
                  for(auto nei:friends[node]){
                        if(vis[nei]==1) continue;
                        vis[nei]=1;
                        temp.push_back(nei);
                        q.push(nei);
                  }
                  }
                  l++;
                  if(l==level){
                      unordered_map<string,int>mp;
                      for(int i=0;i<temp.size();i++){
                            for(auto it:watchedVideos[temp[i]]){
                                 mp[it]++;
                            }
                      }
                      vector<pair<int,string>>p;
                      for(auto it:mp)
                      {
                         p.push_back({it.second,it.first});
                      }
                      sort(p.begin(),p.end());
                      vector<string>ans;
                      for(int i=0;i<p.size();i++){
                          ans.push_back(p[i].second);
                      }
                    //   sort(ans.begin(),ans.end());
                      return ans;
                  }

            }
        return {};
    }
};