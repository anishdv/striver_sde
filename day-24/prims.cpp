//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

// tc - o(Vlog v + (V+E)) so basically VlogV and sc- o(v)

int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        int ans=0;
        
        // i need to make 3 different vectors
        vector<int> weight (V, INT_MAX);
        vector<int> parent (V, -1);
        vector<bool> mst(V, false);
        
        weight[0]=0;
        
        // then we make a min heap to maintain the minimum weight key
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0}); // weight and key
        
        while(!pq.empty()){
            int u= pq.top().second; // key of the min weight
            pq.pop();
            mst[u]=true;
            
            // exploring its neighbors
            for (auto &it: adj[u]){
                int v=it[0];
                int w=it[1];
                
                if (mst[v]==false && weight[v]>w){ // the stored weight is more than explored weight
                    // cout<< v<<" "<<w<< endl;
                    
                    parent[v]=u;
                    weight[v]=w;
                    pq.push({weight[v], v});
                }
            }
            
        }
        for(int i=1; i<V; i++){
            ans+=weight[i];
        }
        return ans;
    }