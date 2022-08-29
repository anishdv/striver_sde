//https://practice.geeksforgeeks.org/problems/number-of-coins1824/1

// tc- o(nt) and sc-o(nt)
//----------------------------MEMOIZATION APPROACH-------------------------------
long long int solve(int coins[],int sum,int i, vector<vector<long long int>>&dp)
   {
       if(i == 0 )
       {
           if (sum%coins[i]==0) return sum/coins[i] ;
           return 1e9 ;
       }
       
       if(dp[i][sum]!=-1)
       {
           return dp[i][sum];
       }
       
        long long int nottake=solve(coins,sum,i-1,dp);
         long long int take=1e9;
        if(sum>=coins[i])
        {   
            take=1+solve(coins,sum-coins[i],i,dp);
        }
        return dp[i][sum]=min(take,nottake) ;
   }
   
	int minCoins(int coins[], int M, int V) 
	{ 
	     vector<vector<long long int>>dp(M, vector<long long int>(V+1,-1));
	    return solve(coins,V,M-1,dp)==1000000000?-1: solve(coins,V,M-1,dp);
	} 

//----------------------------TABULATION APPROACH-------------------------------
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       int siz=coins.size();
        vector<vector<int>> dp(siz+1, vector<int>(amount+1,0));
        
        // filling the first column
        for(int i=0; i<= siz; i++){
            dp[i][0]=0;
        }
        
        // filling the first row
        for(int i=1; i<=amount; i++){
            dp[0][i]=INT_MAX-1;
        }
        
        // now filling the matrix
        for (int i=1; i<=siz; i++){
            for (int j=1; j<=amount; j++){
                if (coins[i-1]<=j){
                    dp[i][j]=min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if (dp[siz][amount]==INT_MAX-1){
            return -1;
        }
        return dp[siz][amount];
        
    }
};
