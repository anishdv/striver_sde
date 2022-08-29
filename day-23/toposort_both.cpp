//https://practice.geeksforgeeks.org/problems/topological-sort/1

//------------------------------DFS METHOD----------------------------------
	void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st ){
	    vis[node]=1;
	    for(auto &it: adj[node]){
	        if (!vis[it]){
	            dfs(it, adj,vis, st);
	        }
	    }
	    st.push(node);
	    return;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>vis(V,0);
	    stack<int> st;
	    vector<int> ans;
	    for(int i=0; i<V; i++){
	        if (!vis[i]){
	            dfs(i,adj, vis, st);
	        }
	    }
	    while(!st.empty()) ans.push_back(st.top()), st.pop();
	    return ans;
	}

//------------------------------BFS METHOD----------------------------------
vector<int> topoSort(int V, vector<int> adj[]){
    vector<int> indegree(V,0);
    vector<int> ans;
    queue<int> q;
    
    // creating an indegree vector
    for(int i=0; i<V; i++){
        for(auto& it: adj[i]){
            indegree[it]++;
        }
    }
    
    // indegree 0 for all those having no edge pointing to it
    for(int i=0; i<V; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int node=q.front(); // this will be of indegree 0
        q.pop();
        ans.push_back(node);
        for(auto &it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return ans;
}