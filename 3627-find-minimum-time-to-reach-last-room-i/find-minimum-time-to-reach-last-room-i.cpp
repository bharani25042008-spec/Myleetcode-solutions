class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > q;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        dist[0][0] = 0;
        q.push({0,0,0});

        while(!q.empty()) {
            auto [d,r,c] = q.top();
            q.pop();

            if(d != dist[r][c])
                continue;

            if(r == n-1 && c == m-1)
                return d;

            for(int i=0;i<4;i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                int nd = max(d, grid[nr][nc]) + 1;

                if(nd < dist[nr][nc]) {
                    dist[nr][nc] = nd;
                    q.push({nd,nr,nc});
                }
            }
        }

        return -1;
    }
};