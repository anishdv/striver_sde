void dfs(TreeNode* root, int level, int dis, map<int,vector<pair<int,int>>> &m){
        if(!root) return;
        m[dis].push_back(make_pair(level,root->val));
        dfs(root->left,level+1,dis-1,m);
        dfs(root->right, level+1, dis+1, m);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> m;
        vector<vector<int>> ans;
        dfs(root,0,0,m); // map is filled properly for hd values and level values
        for(auto it: m){
            sort(it.second.begin(),it.second.end()); // for same hd sort on the basis of level and push them into temp and then into ans
            vector<int> temp;
            for(auto i:it.second) temp.push_back(i.second);
            ans.push_back(temp);
        }
        return ans;
    }