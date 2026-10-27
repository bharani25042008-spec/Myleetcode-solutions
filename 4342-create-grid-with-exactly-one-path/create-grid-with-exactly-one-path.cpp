class Solution {
public:
//vidra
    vector<string> createGrid(int m, int n) {
        vector<string>ans(m,string(n,'#'));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(i==0){
                   ans[i][j]='.';
               }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                  if(j==n-1){
                       ans[i][j]='.';
                  }
            }
        }
        // if(m==1){
        //     string t="";
        //     for(int i=0;i<n;i++)
        //     {
        //         t+='.';
        //     }
        //     ans.push_back(t);
        //     return ans;
        // }
        // if(n==1){
        //     string t="";
        //     while(m--){
        //         t+='.';
        //         ans.push_back(t);
        //         t.clear();
        //     }
        //     return ans;
        // }
        // for(int i=0;i<m;i++){
        //      string t="";
        //      for(int j=0;j<i;j++){
        //          t+='#';
        //      }
        //      for(int j=i;j<n&&j<=i+1;j++){
        //          t+='.';
        //      }
        //      for(int j=i+2;j<n;j++){
        //          t+='#';
        //      }
        //      ans.push_back(t);
        // }
        // string t1="";
        // for(int i=0;i<=n/2;i++){
        //       t1+='.';
        // }
        // for(int i=(n/2)+1;i<n;i++){
        //       t1+='#';
        // }
        // ans.push_back(t1);
        // t1.clear();
        // for(int i=0;i<n/2;i++){
        //     t1+='#';
        // }
        // for(int i=n/2;i<n;i++){
        //     t1+='.';
        // }
        // ans.push_back(t1);
        // m-=2;
        // while(m--){
        //     string t="";
        //     for(int i=0;i<=(n/2);i++){
        //         t+='#';
        //     }
        //     for(int i=(n/2)+1;i<n;i++){
        //         t+='.';
        //     }
        //     ans.push_back(t);
        // }
        // for(int i=0;i<m;i++){
        //     string t="";
        //     if(i==m-1){
        //          if(i-1%2==1){
        //              for(int j=0;j<=n/2;j++){
        //                   t+='#';
        //              }
        //              for(int j=(n/2)+1;j<n;j++){
        //                  t+='.';
        //              }
        //         ans.push_back(t);
        //          return ans;
        //          }
        //     }
        //     if(i%2==0){
        //         for(int j=0;j<=n/2;j++){
        //              t+=".";
        //         }
        //         for(int j=(n/2)+1;j<n;j++){
        //             t+='#';
        //         }
        //     }else{
        //         for(int j=0;j<(n/2);j++){
        //              t+='#';
        //         }
        //         for(int j=(n/2);j<n;j++){
        //              t+='.';
        //         }
        //     }
        //     ans.push_back(t);
        // }
        return ans;
    }
};