//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// works on greedy algorithm.. choose edges in greedy order
// tc -O((V+E)LogV)
// doesnt work for negative edges graphs

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dis(V, INT_MAX);
        dis[S]=0;
        
        // creating a min heap and it is of node weight type
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({S,0});
        while(!pq.empty()){
            pair<int, int> p=pq.top();
            int node=p.first;
            // int weight=p.second; because it is already in dis vector
            pq.pop();
            for(auto &it: adj[node]){
                int n= it[0];
                int w= it[1];
                if (dis[n]> dis[node]+w){
                    dis[n]=dis[node]+w;
                    pq.push({n,dis[n]});
                }
            }
        }
        return dis;
    }