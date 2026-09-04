class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
          int maxi=*max_element(lights.begin(),lights.end());
          int idx=0;
          for(int i=0;i<lights.size();i++){
             if(lights[i]==maxi){
                   idx=i;
                   break;
             }
          }
          int ans=INT_MIN;
          for(int i=0;i<arrivalTime.size();i++){
            int val=0;
               int r=arrivalTime[i]%period;
               if(r<maxi){
                  val=0;
               }else{
                 val=period-r;
               }
               ans=max(ans,val);
          }
          return ans;
          //it was a bit scary at the beginning but i must believe in myself to shine i can but something itside me called the laziness is prohibiting me from doing these stuff....
          
    }
};