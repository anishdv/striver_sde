// this is solution to https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while (start<=end){
            int mid = start +(end-start)/2;
            if (target== nums[mid]){
                return mid;
            }
            if (nums[start]<=nums[mid]){// left sorted
                if (target>=nums[start]&& target<nums[mid]){
                    end=mid-1;
                }
                else {
                    start=mid+1;
                }
            }
            else{// right sorted
                if (target>nums[mid] && target<=nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};