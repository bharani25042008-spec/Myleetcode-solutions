class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
       long long ans=0;
       priority_queue<int>pq;
       for(int i=0;i<grid.size();i++){
             sort(grid[i].begin(),grid[i].end());
             reverse(grid[i].begin(),grid[i].end());
             int l=limits[i];
             for(int j=0;j<l;j++){
                    pq.push(grid[i][j]);
             }
       }
       while(!pq.empty()&&k>0){
              k--;
              ans+=pq.top();
              pq.pop();
       }
        return ans;
    }
};