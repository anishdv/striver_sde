// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

void dfs(int node, vector<int> &vis,vector<int> adj[], vector<int> &ans){
        if (vis[node]==1){
            return;
        }
        
        ans.push_back(node);
        vis[node]=1;
        for(int i=0; i<adj[node].size(); i++){
            dfs(adj[node][i], vis, adj, ans);
        }
        return;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vector<int> ans;
        dfs(0,vis, adj, ans);
        return ans;
    }