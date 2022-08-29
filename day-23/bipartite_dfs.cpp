//https://www.codingninjas.com/codestudio/problems/920551?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1


//-----------------------------------------odd cycle exists or not method-----------------------------------------------------------
#include <bits/stdc++.h>

bool oddcyclen(int node, vector<int> &vis, unordered_map<int, vector<int>> &mp, vector<int> &position, int cnt){
    vis[node]=1;
    position[node]=cnt;
    for (auto &it: mp[node]){
        if (position[it]!=-1 && position[it]!=cnt-1){
            if ((cnt-position[it]+1)%2!=0) return true;
        }
        else if (position[it]==-1 && oddcyclen(it, vis, mp, position, cnt+1)) return true;
    }
    return false;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    // if it doesnt have cycle then it will be bipartite
    // if it has cycle then we need to check the cycle length
    // if even it will be bipartite
    // if odd it will not be biprartite
    
    // n is also number of vertices
    int n=edges.size();
    
    // visited array
    vector<int> vis(n,0);
    
    // position array
    vector<int> position(n,-1);
    
    // adjacency map
    unordered_map<int, vector<int>> mp;
    
    // conversion from adjacency matrix to adjacency map
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (edges[i][j]==1){
                mp[i].push_back(j);
                mp[j].push_back(i);            
            }
        }
    }
    
    // traversal on every node
    for(int i=0; i<n; i++){
        int cnt=0;
        if(!vis[i]){
            position[i]=cnt;
            if (oddcyclen(i, vis, mp, position, cnt+1)){
                return false;
            }
        }
    }
    return true;
}


// -------------------------------------------------------node neighbors has color different than node method---------------------------
// before recursion, if it is unvisited, color for it is alloted
bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!bipartiteDfs(it, adj, color)) {
                return false; 
            }
        } else if(color[it] == color[node]) return false; 
    }
    return true; 
}

bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color);  // if it is not given color then it is -1 initially
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!bipartiteDfs(i, adj, color)) {
                return false;
            }
        } 
    }
    return true; 
}