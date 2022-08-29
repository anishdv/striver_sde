// https://leetcode.com/problems/partition-equal-subset-sum/

//----------------memoization approach----------------------
// tc-o(n+ n*sum/2) sc-o(n*sum/2)

bool helper(vector<int> &nums, int index, int target, int n,vector<vector<int>> &dp){
        if(target==0) return dp[index][0]=true;
        if (index==n) return dp[index][target]=false;
        
        if (dp[index][target]!=-1) return dp[index][target];
        
        if (nums[index]<=target){
            return dp[index][target]=(helper(nums, index+1, target, n,dp)|| helper(nums, index+1, target-nums[index], n,dp));
        }
        else{
            return dp[index][target]=helper(nums, index+1, target, n,dp);
        }
    }
    bool canPartition(vector<int>& nums) {
        // total sum of nums should be even
        // then it will be like find the subset of nums having total of sum/2
        int n=nums.size();
        int sum=0;
        for(auto &it: nums){
            sum+=it;
        }
        
        if (sum%2!=0) return false;
        
        vector<vector<int>> dp(n+1, vector<int> (sum/2+1, -1));
        return helper(nums, 0, sum/2, n,dp );
    }


    //-----------------tabulation approach---------------------------

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto& it: nums){
            sum+=it;
        }
        
        if(sum%2!=0){
            return false;
        }
        
        vector<vector<int>> dp(n+1, vector<int> (sum/2+1,0));
        
        int target=sum/2;
        
        // 1 in dp represents true and 0 for false
        
        for (int i=0; i<=n; i++){
            dp[i][0]=1;
        }
        
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
                if (nums[i-1]<=j){
                    dp[i][j]= (dp[i-1][j] || dp[i-1][j-nums[i-1]]);
                }
                else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }