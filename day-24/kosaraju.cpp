//https://www.codingninjas.com/codestudio/problems/985311?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>

void dfs1(int node, vector<vector<int>> &edges, vector<int>&vis, stack<int> &st){
    vis[node]=1;
    for (auto &it: edges[node]){
        if (!vis[it]) dfs1(it, edges, vis, st);
    }
    st.push(node);
    return;
}
void dfs2(int node, vector<vector<int>> &transpose, vector<int> &vis, vector<int> &scc){
    vis[node]=1;
    for (auto &it:transpose[node]){
        if(!vis[it]) dfs2(it, transpose, vis, scc);
    }
    scc.push_back(node);
    return;
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // 1.sort the vertices in the order of finishing time using a stack in which the top element will be the one that will finish in end,tc--o(n+e)
    vector<vector<int>> ans;
    vector<vector<int>> edge(n);
    for(auto &it: edges){
        edge[it[0]].push_back(it[1]);
    }
    stack<int> st;
    vector<int> vis(n,0);
    for (int i=0; i<n; i++){
        if (!vis[i]){
            dfs1(i, edge,vis, st);
        }
    }
//     cout<<st.size()<<endl;
    
    //2. will store transpose of the graph, tc-o(n+e) sc-o(n+e) 
    vector<vector<int>> transpose(n);
    for (int i=0; i<n; i++){
        vis[i]=0;
        for(auto it:edge[i]){
            transpose[it].push_back(i);
        }
    }
    //3. run a dfs in order of toposorted stack but on transposed graph, tc-o(n+e), sc-o(n+e) for visited array
    
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
        vector<int> scc;
        dfs2(node, transpose, vis,scc);
        ans.push_back(scc);
        }
    }
    return ans;
}