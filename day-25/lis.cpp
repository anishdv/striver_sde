// this is solution to https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // TABULATION DP
        
        // int n = nums.size();
        // vector<int> dp(n, 1);
        // for (int i = 0; i < n; ++i)
        //     for (int j = 0; j < i; ++j)
        //         if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
        //             dp[i] = dp[j] + 1;
        // return *max_element(dp.begin(), dp.end());
        // tc- o(n2) space- o(n)
        
        // BINARY SEARCH
        int n=nums.size();
        int ans=1;
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for(int i=1; i<n; i++){
            if (nums[i]>temp.back()){
                temp.push_back(nums[i]);
                ans++;
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(), nums[i])- temp.begin();
                temp[ind]=nums[i];
            }
        }
        return ans;
        
        // tc- o(nlogn) sc-o(n)
    }
};