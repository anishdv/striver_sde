//-----------------memoization approach-----------------------

// tc-o(mn) and sc-o(mn)+o(m+n)
int helper(int i, int j, string& word1, string& word2,vector<vector<int>>& dp){
        if (i<0) return j+1;
        if (j<0) return i+1;
        if (dp[i][j]!=-1) return dp[i][j];
        
        if (word1[i]==word2[j]) return dp[i][j]=helper(i-1,j-1, word1, word2,dp);
        else{
            return dp[i][j]=1+ min(helper(i-1,j,word1,word2,dp), min(helper(i,j-1,word1,word2,dp), helper(i-1,j-1,word1,word2,dp)));
        }
    }
    
    
    int minDistance(string word1, string word2) {
        int sz1= word1.size();
        int sz2=word2.size();
        vector<vector<int>> dp(sz1, vector<int>(sz2,-1));
        
        return helper(sz1-1, sz2-1, word1, word2,dp);
    }

//-----------------tabulation approach-----------------------

// tc-o(mn) and sc-o(mn)
int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp (n+1, vector<int>(m+1,0));
        
        // filling with base cases..earlier we were using 0-based indexing now we are using 1-based indexing
        for(int i=0; i<=n; i++){
            dp[i][0]=i;
        }
        for(int i=0; i<=m; i++){
            dp[0][i]=i;
        }
        
        // filling the left cells
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if (word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                
                else{
                    dp[i][j]= 1+ min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }