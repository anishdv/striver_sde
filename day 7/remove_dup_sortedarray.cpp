// this is solution to https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0) return 0;
        int prev=nums[0];
        int jumpIn=1;
        for(int i=1; i<nums.size();i++){
            if (nums[i]!=prev){
                nums[jumpIn]=nums[i];
                jumpIn+=1;
                prev=nums[i];
            }
        }
        return jumpIn;
    }
};