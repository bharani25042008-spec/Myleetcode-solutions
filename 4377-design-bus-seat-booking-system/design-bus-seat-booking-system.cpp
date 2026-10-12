class BusBooking {
public:
map<string,int>mp;
int tot=0;
int mini=0;
    BusBooking(int n) {
        
    }
    
    void toggle(string seat) {
         char c=seat[0];
         if(mp.find(seat)!=mp.end()){
             tot-=mp[seat];
              mp.erase(seat);
              mini--;
         }else{
         if(c=='B'||c=='C'){
              mini++;
              tot++;
              mp[seat]+=1;
         }else{
             if(c=='A'){
                 string s="B"+seat.substr(1);
                 if(mp.find(s)!=mp.end()){
                      tot+=3;
                      mini++;
                      mp[seat]+=3;
                 }else{
                     tot+=1;
                     mini++;
                      mp[seat]+=1;
                 }
             }else if(c=='D'){
                 string s="C"+seat.substr(1);
                 if(mp.find(s)!=mp.end()){
                      tot+=3;
                      mini++;
                      mp[seat]+=3;
                 }else{
                     tot++;
                      mini++;
                      mp[seat]+=1;
                 }
             }
         }
         }
    
    }
    
    int getTotalTime() {
          if(tot<0) return 0;
          return tot;
    }
    
    int getMinTime() {
          if(mini<0) return 0;
          return mini;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */