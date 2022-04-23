// this is a solution to https://leetcode.com/problems/reverse-pairs/
// tc nlogn
//sc n

class Solution {
public:
    int merge(vector<int> &nums, int low, int mid, int high){
        int i= low;
        int j= mid +1;
        
        int total=0;
        
        // we are counting the reverse pairs
        while (i<=mid){
            while (j<=high && nums[i]> 2 * (long long) nums[j]){
                j++;
            }
            total += (j-(mid+1));
            i++;
        }
        
        // we need to make sorted combination of both parts
        vector<int> t;
        int left=low, right=mid+1;
        while(left<=mid && right <= high){
            if (nums[left]>=nums[right]){
                t.push_back(nums[right++]);
            }
            else {
                t.push_back(nums[left++]);
            }
        }
        while (left<=mid){
            t.push_back(nums[left++]);
        }
        while (right<=high){
            t.push_back(nums[right++]);
        }
        
        // copy the sorted combination in nums
        for (int i = low; i <= high; i++) {
            nums[i] = t[i - low];
        }
        return total;
    }
    int mergeSort(vector<int>& nums, int low, int high){
        if (low>=high){
            return 0;
        }
        int mid=low+(high-low)/2;
        int rev=0;
        rev=mergeSort(nums, low, mid);
        rev+=mergeSort(nums, mid+1, high);
        rev+=merge(nums, low, mid, high);
        return rev;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};