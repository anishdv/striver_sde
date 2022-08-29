
//https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    //--------------------------DFS APPROACH---------------------
    
    void mark_island (int i, int j,vector<vector<char>>& grid, int r, int c ){
        if (i<0 || i>=r || j<0 || j>=c|| grid[i][j]!='1'){
            return;
        }
        grid[i][j]='2';
        mark_island(i+1,j,grid,r,c);
        mark_island(i-1,j,grid,r,c);
        mark_island(i,j+1,grid,r,c);
        mark_island(i,j-1,grid,r,c);
        return;
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        // fast i/o
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int r=grid.size();
        int c=grid[0].size();
        int cnt=0;
        
        for(int i=0; i<r ; i++){
            for(int j=0; j<c; j++){
                if (grid[i][j]=='1'){
                    mark_island(i,j, grid, r ,c);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    //--------------------------BFS APPROACH---------------------
    int numIslands(vector<vector<char>>& grid){
        int m=grid.size();
        if(m==0) return 0;
        vector<vector<int>> offset={{1,0},{0,1},{-1,0},{0,-1}};
        int cnt=0;
        int n=grid[0].size();
        for(int i=0;i<m; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j]=='1'){
                    cnt++;
                    queue<pair<int,int>> q;
                    grid[i][j]='0';
                    q.push({i,j});
                    while(!q.empty()){
                        int r,c;
                        for (int i=0;i<4; i++){
                        r=q.front().first + offset[i][0];
                        c=q.front().second + offset[i][1];
                        if(r>=0 && r<m && c>=0 && c<n && grid[r][c]=='1'){
                            q.push({r,c});
                            grid[r][c]='0';
                        }
                    }
                        q.pop();
                    }
                }
            }
        }
        return cnt;
    }
};