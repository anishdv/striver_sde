// https://leetcode.com/problems/coin-change-2/


// tc- o(nt) and sc- o(nt)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int siz=coins.size();
        vector<vector<int>> dp(siz+1, vector<int>(amount+1,0));
        
        // filling the first row
        for(int i=1; i<= amount; i++){
            dp[0][i]=0;
        }
        
        // filling the first column
        for(int i=0; i<=siz; i++){
            dp[i][0]=1;
        }
        
        // now filling the matrix
        for (int i=1; i<=siz; i++){
            for (int j=1; j<=amount; j++){
                if (coins[i-1]<=j){
                    dp[i][j]=dp[i-1][j] + dp[i][j-coins[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[siz][amount];
    }
};