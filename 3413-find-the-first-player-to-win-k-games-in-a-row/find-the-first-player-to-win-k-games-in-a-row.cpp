class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        //can i use a dq and map
        map<int,int>mp;
        deque<int>dq;
        for(auto it:skills){
               dq.push_back(it);
        }
        int n=skills.size();
        map<int,int>id;
        for(int i=0;i<n;i++){  
            id[skills[i]]=i;
        }
         int maxi=*max_element(skills.begin(),skills.end());
        if(skills.size()<k) return id[maxi];
        while(dq.size()>1){
              int top1=dq.front();
              dq.pop_front();
              int top2=dq.front();
              dq.pop_front();
              if(top1>top2){
                  dq.push_front(top1);
                  mp[top1]+=1;
                  dq.push_back(top2);
                  if(mp[top1]==k) return id[top1];
                 
              }else{
                    dq.push_front(top2);
                    mp[top2]+=1;
                    dq.push_back(top1);          
                    if(mp[top2]==k) return id[top2];
              }
        }
        return 0;
    }
};