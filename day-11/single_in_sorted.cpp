// this is solution to https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int end=nums.size()-2;
        while (start<=end){
            int mid=(end+start)>>1;
            if (nums[mid]==nums[mid^1]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return nums[start];
    }
};