//----------------------------------------BFS METHOD---------------------------------
#include <bits/stdc++.h>
// before pushing into queue, if it is unvisited, color for it is alloted
bool bipartite(int node, unordered_map<int, vector<int>> &mp, int color[]){
    queue<int> q;
    color[node]=1;
    q.push(node);
    
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto &it:mp[x]){
            if (color[it]==-1){
                color[it]=1-color[x]; // complimentary color is alloted to neighbors
                q.push(it);
            }
            else if (color[it]== color[x]){
                return false;
            }
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    int n=edges.size();
    int color[n];
    unordered_map<int, vector<int>> mp;
    memset(color,-1,sizeof color);
    
    // maintaining adjacency map
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(edges[i][j]==1){
                mp[i].push_back(j);
                mp[j].push_back(i);
            }
        }
    }
    
    // traversing over vertices
    for (int i=0; i<n; i++){
        if (color[i]==-1){
             if (!bipartite(i, mp, color)){
                return false;
             }
        }
    }
    return true;
}