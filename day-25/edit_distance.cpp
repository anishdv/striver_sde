// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

int matrixMultiplication(int N, int arr[])
   {
       // n-1 because of the way we are getting dimensions
       vector<vector<int>> dp( N - 1 , vector<int> ( N - 1 ));
       int n = N;
       for( int gap = 0 ; gap < n - 1; gap++){
           for(int i = 0 , j = gap; j < n - 1  ; i++, j++){
               if ( gap == 0 ){
                   dp[i][j] = 0;
               }
               else if ( gap == 1 ){
                   dp[i][j] = arr[i] * arr[j] *  arr[j + 1];
               }
               else {
                   int mini = 1e9;
                   for(int k = i; k < j ; k++){
                       int lc = dp[i][k];
                       int rc = dp[k + 1][j];
                       int mc = arr[i] * arr[k + 1] * arr[j + 1];
                       
                       mini = min ( mini, lc + rc + mc );
                   }
                   
                   dp[i][j] = mini;
               }
           }
       }
       
       return dp[0][n - 2];
   }