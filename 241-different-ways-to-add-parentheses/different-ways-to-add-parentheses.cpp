class Solution {
public:
vector<int> func(string s){
         // return type is a vector
         //so an answer array
         vector<int>ans;
         // ippo string la traverse panna poren
         for(int i=0;i<s.length();i++){
               //inga than symbols paatha split pannanum
               //so left and right string generate panna poren
               if(s[i]=='+'||s[i]=='-'||s[i]=='*'){
                     //left  from starting la irundhu to current symbol ku munnadi
                     string left=s.substr(0,i);
                     //right inga current symbol la irundhu next ending varikum
                     string right=s.substr(i+1);
                     //after this 
                     //left la 2 irukum
                     //right la (1-1) irukum so idhukulla irukka symbols aiyum evaluate panni numbers ah maathanum andha number ah two separate vectors la store pannuven
                     vector<int>l=func(left);
                     vector<int>r=func(right);
                     //ippo generate panna numbers ah symbols vechu simply pannanum
                     for(auto x:l){
                           for(auto y:r){
                               // iruka expression la enna symbol iruko same symbol vechi evaluate pannanum
                               //indha edathula suppose string expressions la (i.e) left and right endha symbols um illana just adha numbers ah convert pannanum 
                               if(s[i]=='+'){
                                    ans.push_back(x+y);
                               }else if(s[i]=='-'){
                                     ans.push_back(x-y);
                               }else{
                                   ans.push_back(x*y);
                               }
                           }
                     }
               }
         }// ok . nu solli oru operator eh illa 
         //it should be +
         //suppose endha symbols um left and right la illana ans empty ah irukum so appo andha edathula oru digit than irukum andha just number ah maathi add panna podhum
         if(ans.empty()){
                 ans.push_back(stoi(s));
         }
         return ans;
}
    vector<int> diffWaysToCompute(string exp) {
            
            //ok problem purincha
            //mm purinchathu
            //ok every possible bracket sequences um generate pannanum
            //but only in the case of symbols
            // symbols than namma splitting points
            //each symbol paakrappaium left and right halfs ku solve pannanum 
            // so recursion.
            //ok
            //enna aachu
            //zero la  prachana wait paakren
            
            return func(exp);
    }
};