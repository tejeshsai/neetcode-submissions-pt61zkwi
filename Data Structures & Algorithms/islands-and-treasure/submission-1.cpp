class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<pair<int,int>> dirs{
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };
        
        queue<pair<int, int>> q;

        int rows = grid.size();
        int cols = grid[0].size();

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]==0){
                    q.push({r,c});
                }
            }
        }

        while(!q.empty()){
            auto co = q.front();
            q.pop();

            int row = co.first;
            int col = co.second;
            for(auto dr:dirs){
                int nr = row+dr.first;
                int nc = col+dr.second;
                if(nr < 0 || nr>=rows|| nc <0 || nc>=cols) continue;
                if(grid[nr][nc]==INT_MAX){
                    grid[nr][nc] = 1+grid[row][col];
                    q.push({nr, nc});
                }
            }
        }
        
    }
};
