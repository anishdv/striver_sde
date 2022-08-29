//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

void helper(int hd, int level, map<int, pair<int,int>> &mp, Node* temp){
      if (!temp) return;
      
      if (mp.find(hd)==mp.end()){
          mp[hd].first=level;
          mp[hd].second=temp->data;
      }
      else{
          if (mp[hd].first<=level){
              mp[hd].first=level;
              mp[hd].second=temp->data;
          }
      }
      
      helper(hd-1, level+1, mp, temp->left);
      helper(hd+1, level+1, mp, temp->right);
      return;
  }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        // we will go from min value of hd to max value of hd for a loop going from max value of level
        // to min value of level
        vector<int> ans;
        map<int, pair<int,int>> mp; // hd  level,val
        helper(0,0,mp, root);
        for (auto &it: mp){
            ans.push_back(it.second.second);
        }
        return ans;
    }



// level order traversal so that level is not need to be handled
    vector <int> bottomView(Node *root) {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second;   
            mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;  
    }