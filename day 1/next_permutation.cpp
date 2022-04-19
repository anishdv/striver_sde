// this is solution to https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        int l=0;
        for (k=n-2; k>=0; k--){
            if (nums[k]<nums[k+1]){// finding breakpoint in curve.. greater value at greater position is required
                break; 
            }
        }
        
        if (k<0){
            reverse(nums.begin(),nums.end());
        }else{
            for(l=n-1; l>k;l--){ // from right the first element which is greater than breakpoint will be swapped with breakpoint
                if (nums[l]>nums[k]){ 
                    break;
                }
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }

    }
};