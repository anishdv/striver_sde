// this is solution to https://leetcode.com/problems/maximum-subarray/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans= INT_MIN;
        int sum=0;
        for (int i=0; i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans,sum); // even if sum is negative whether it is larger or not
            if (sum<0)sum=0; // for negative sum we wont proceed with keeping negative sums
        }
        return ans;
        
    }
};
