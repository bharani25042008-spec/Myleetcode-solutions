class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
            int ans=0;
            for(int i=1;i<colors.size()-1;i++){
                   if(colors[i]!=colors[i-1]&&colors[i]!=colors[i+1]){
                              ans++;
                   }
            } 
            if(colors.size()>1){
                  int sl=colors[colors.size()-2];
                  int l=colors[colors.size()-1];
                  if(l!=colors.front()&&l!=sl){
                       ans++;
                  }
                  if(colors.back()!=colors.front()&&colors.front()!=colors[1]){
                       ans++;
                  }
            }
            return ans;
    }
};