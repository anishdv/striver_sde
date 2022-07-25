<<<<<<< HEAD
// this is solution to https://leetcode.com/problems/unique-paths/

class Solution {
public:

    // DP solution
    int help(int i, int j,int m , int n , vector<vector<int>> &dp){
        if (i==m && j==n){
            return 1;
        }
        if (i>m || j>n){
            return 0;
        }
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        else return dp[i][j]=help(i+1,j, m, n ,dp)+help(i,j+1,m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1)); // we define dp like this
        return help(0,0,m-1, n-1 , dp);
    }
   
   // combinatorics solution
   int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
    //     return help(0,0,m-1, n-1 , dp);
         int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }


=======
// this is solution to https://leetcode.com/problems/unique-paths/

class Solution {
public:

    // DP solution
    int help(int i, int j,int m , int n , vector<vector<int>> &dp){
        if (i==m && j==n){
            return 1;
        }
        if (i>m || j>n){
            return 0;
        }
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        else return dp[i][j]=help(i+1,j, m, n ,dp)+help(i,j+1,m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1)); // we define dp like this
        return help(0,0,m-1, n-1 , dp);
    }
   
   // combinatorics solution
   int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
    //     return help(0,0,m-1, n-1 , dp);
         int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }


>>>>>>> 6e6d19c66866201a446620d1a1b7c321f6b69db2
};