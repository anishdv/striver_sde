// // this question is different from that of undirected because there can be case that if from two nodes we are reaching a specific node A then it is not a cycle because both have their tails at A

#include <bits/stdc++.h>
// //-----------------------------DFS METHOD-----------------------------
bool cycleCheck(int node, vector<int> &vis,vector<int> &dfsvis, unordered_map<int,vector<int>> &mp){
    vis[node]=1;
    dfsvis[node]=1;
//     if (mp[node].size()==0) return false; -- if we write it here it will end without dfsvis=0
    for(auto &it: mp[node]){
        if (!vis[it]){
            if (cycleCheck(it, vis,dfsvis, mp)) return true;
        }
        else if (dfsvis[it]) return true;
    }
    dfsvis[node]=0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    
    unordered_map<int, vector<int>> mp(n+1);
    
    // maintaining the mapping
    for(auto &it: edges){
        mp[it.first].push_back(it.second);
    }
    // visited array
    vector<int> vis(n+1,0);
    vector<int> dfsvis(n+1,0);
    
    //looping over components
    for(int i=1; i<=n; i++){
        if (!vis[i]){
            if (cycleCheck(i,vis,dfsvis, mp)){
                return true;
            }
        }
    }
    return false;
}

//-----------------------------BFS METHOD-----------------------------
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges){
    // we will try to use kahn algorithm for topological sort and if ans is shorter than number of vertices then there exists a cycle....topo sort--DAG
    vector<int> indegree(n+1,0);
    queue<int> q;
    vector<int> ans;
    unordered_map<int, vector<int>> mp(n+1);
    
    for(auto &it: edges){
        mp[it.first].push_back(it.second);
    }
    
    for(int i=1; i<=n; i++){
        for(auto& it: mp[i]){
            indegree[it]++;
        }
    }
    for(int i=1; i<=n; i++){
        if (indegree[i]==0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto &it:mp[node]){
            indegree[it]--;
            if (indegree[it]==0){
                q.push(it);
            }
        }
    }
    if (ans.size()!=n) return true;
    return false;
    
}