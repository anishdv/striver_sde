// this is solution to https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    void help(vector<int>& nums, int ind, int t,vector<int> &ds, vector<vector<int>> &ans){
        if (t==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind; i<nums.size(); i++){
            if (i>ind && nums[i]==nums[i-1]){continue;}
                if (nums[i]>t){
                    break;
                }
                ds.push_back(nums[i]);
                help(nums, i+1, t-nums[i],ds, ans);
                ds.pop_back();
            }
        }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        help(candidates,0, target, ds, ans);
        return ans;
    }
};