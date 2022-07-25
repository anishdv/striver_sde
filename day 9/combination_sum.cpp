// this is solution to https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void findCombination(vector<int>& candidates,int target, int i, vector<vector<int>> &ans, vector<int>&ds){
        if(i==candidates.size()){ // base case
            if (target==0){
                ans.push_back(ds);
            }
            return;
        }
        //pick up the element to choose whether to add it in ds
        if(candidates[i]<=target){
            ds.push_back(candidates[i]);
            findCombination(candidates,target-candidates[i],i,ans,ds);
            ds.pop_back();
        }
        findCombination(candidates,target, i+1, ans,ds);
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        findCombination(candidates, target,0,ans,ds);
        return ans;
    }
};