class Solution {
public:
    int maximumGap(string skill, string station) { 
        vector<int>left(skill.size());
        vector<int>right(skill.size());
        int prev=-1;
        for(int i=0;i<skill.size();i++){
              for(int j=prev+1;j<station.size();j++)
              {
                 if(skill[i]==station[j]){
                      left[i]=j;
                      prev=j;
                      break;
                 }
              }
        }
        int next=station.size();
        for(int i=skill.size()-1;i>=0;i--){
            for(int j=next-1;j>=0;j--)
            {
                 if(station[j]==skill[i]){
                     right[i]=j;
                     next=j;
                     break;
                 }
            }
        }
        int maxi=0;
        for(int i=0;i<skill.size()-1;i++){
             maxi=max(maxi,right[i+1]-left[i]);
        }
        return maxi;
    }
};