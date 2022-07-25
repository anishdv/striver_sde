    // this is solution to https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
    
    void help(vector<vector<int>> &m, int i, int j, int n,vector<string> &ans, string s ){
        if (i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        
        if (i+1<n && m[i+1][j]==1 ){
            m[i][j]=0;
            help(m, i+1, j, n, ans, s+'D');
            m[i][j]=1;
        }
        if (j-1>=0 && m[i][j-1]==1 ){
            m[i][j]=0;
            help(m, i, j-1, n, ans, s+'L');
            m[i][j]=1;
        }
        if (j+1<n && m[i][j+1]==1 ){
            m[i][j]=0;
            help(m, i, j+1, n, ans, s+'R');
            m[i][j]=1;
        }
        if (i-1>=0 && m[i-1][j]==1 ){
            m[i][j]=0;
            help(m, i-1, j, n, ans, s+'U');
            m[i][j]=1;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string s="";
        if (m[0][0]) help(m, 0,0, n, ans,s);
        return ans;
    }