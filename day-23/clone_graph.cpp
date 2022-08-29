//https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* cur, unordered_map<Node*, Node*>& mp){
        Node* cloneCur= new Node(cur->val);
        mp[cur]= cloneCur;
        vector<Node* > cloneNeigh;
        for (auto &it: cur->neighbors){
            if (mp.find(it)!=mp.end()){
                cloneNeigh.push_back(mp[it]); // if it is already explored then just push it in cloneCur
            }
            else {
                cloneNeigh.push_back(dfs(it, mp)); //  if it has not been explored then explore it first and return its deep copy node 
            }
        }
        cloneCur->neighbors=cloneNeigh;
        return cloneCur;
    }
    
    Node* cloneGraph(Node* node) {
        if (node==NULL) return NULL;
        if (node->neighbors.size()==0){
            Node* clone= new Node(node->val);
            return clone;
        }
        unordered_map<Node*, Node*> mp; // it has original and clone nodes
        return dfs(node, mp);
    }
};