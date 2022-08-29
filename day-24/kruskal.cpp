	// it is by using union find method and concept of disjoint sets

    // tc - O(MlogM for sorting edges) + O(M*4alpha for putting into same component)
    // sc- o(M for edges)+ O(N for parent array)+ O(N for rank array)
    
    // Making a struct node
	struct node{
	    int u;
	    int v;
	    int wt;
	    node(int first, int second, int weight){
	        u=first;
	        v=second;
	        wt=weight;
	    }
	};
	
	// comparator function for sorting edges
	bool static cmp(node a , node b){
	    return a.wt<b.wt;
	}
	
	// findPar function
	int findPar(int a, vector<int> &parent){
	    if (a== parent[a]){
	        return a;
	    }
	    return parent[a]=findPar(parent[a], parent);
	}
	
	// union function 
	void unionn(int a, int b,vector<int> &parent, vector<int> &rank){
	    // we need to find the rank of parents of a and b
	    a=findPar(a,parent);
	    b=findPar(b, parent);
	    if (rank[a]>rank[b]){
	        parent[b]=a;
	    }
	    else if (rank[a]<rank[b]){
	        parent[a]=b;
	    }
	    else{
	        parent[a]=b;
	        rank[b]++;
	    }
	    return;
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<node> edges;
        vector<int> parent(V);
        vector<int> rank(V,0);
        int cost=0;
        
        // self parenting 
        for(int i=0; i<V; i++){
            parent[i]=i;
        }
        
        // converting adj into edges array of nodes
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                edges.push_back({i, adj[i][j][0], adj[i][j][1]});
            }
        }
        
        // sorting the edges in increasing order of their weights
        sort(edges.begin(), edges.end(), cmp);
        
        
        // making components
        for( auto &it: edges){
            if (findPar(it.u, parent)!=findPar(it.v, parent)){
                cost+=it.wt;
                unionn(it.u, it.v, parent, rank);
            }
        }
        
        return cost;
    }