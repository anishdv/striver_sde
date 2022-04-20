// this is solution to https://leetcode.com/problems/merge-sorted-array/
// in this problem num1 has a capacity of m+n already

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        
        // start inserting the element from the end nums1[]
        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }
            else{
                nums1[k--]=nums2[j--];
            }
        }
    }
};