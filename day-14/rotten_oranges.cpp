//https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    
    // tc- o(4n) sc - o(2n)
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0, time=0, tot=0;
        queue<pair<int, int>> rotten;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j]!=0) tot++; // all the non zero elements 
                if (grid[i][j]==2) rotten.push({i,j});
            }
        }
        
        int dx[4]={0,0,1,-1};
        int dy[4]={-1,1,0,0};
        
        while(!rotten.empty()){
            int k=rotten.size();
            cnt+=k; // all the rotten elements are counted in cnt
            while(k--){
                int x=rotten.front().first;
                int y=rotten.front().second;
                rotten.pop();
                for(int i=0; i<4; i++){
                    int nx=x+dx[i], ny= y+dy[i];
                    if (nx>=m || ny>=n || nx<0 || ny<0 || grid[nx][ny]!=1) continue;
                    grid[nx][ny]=2;
                    rotten.push({nx,ny});
                }
            }
            if (!rotten.empty()) time++;
            
        }
        return tot==cnt? time : -1;
    }
};