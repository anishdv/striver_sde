//https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU

// tc - O(VE)
// dp
// works for negative weights but not for negative weight cycles

vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dis(V, 1e8);
        dis[S]=0;
        int e= adj.size();
        
        // i need to relax edges v-1 times
        for(int t=0; t<V-1; t++){
            for (int i=0; i<e; i++){
                int src= adj[i][0];
                int dest=adj[i][1];
                int weight= adj[i][2];
                if (dis[src]!=INT_MAX && weight+ dis[src]< dis[dest]){
                    dis[dest]=weight+dis[src];
                }
            }
        }
        
        // if any edge can be relaxed further then it has negative weight cycle
        for(int i=0; i<e; i++){
            int src= adj[i][0];
            int dest=adj[i][1];
            int weight= adj[i][2];
            if (dis[src]!=INT_MAX && weight+ dis[src]< dis[dest]){
                cout<<"negative edge cycle exists"<< endl;
            }
        }
        
        return dis;
    }