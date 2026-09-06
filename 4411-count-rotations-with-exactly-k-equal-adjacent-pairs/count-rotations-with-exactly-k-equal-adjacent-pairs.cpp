class Solution {
public:
bool func(deque<char>q,int k){
     int c=0;
     for(int i=0;i<q.size()-1;i++){
         if(q[i]==q[i+1]) c++;
     }
     return c==k;
}
    int countRotations(string s, int k) {
        deque<char>q(s.begin(),s.end());
        int ans=0;
        int n=s.length();
        while(n--){
            char c=q.front();
            q.pop_front();
            q.push_back(c);
            if(func(q,k)) ans++;
        }
        return ans;
    }
};