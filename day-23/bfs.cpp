//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V+1,0);
        vector<int> ans;
        if (!vis[0]){
            queue<int> q;
            q.push(0);
            vis[0]=1;
            while(!q.empty()){
                int x=q.front();
                q.pop();
                ans.push_back(x);
                for(auto &i:adj[x]){
                    if (!vis[i]){
                        q.push(i); // the time we are pushing it into queue that time only we need to do vis=1 for that
                        vis[i]=1;
                    }
                }
            }
        }
        return ans;
    }