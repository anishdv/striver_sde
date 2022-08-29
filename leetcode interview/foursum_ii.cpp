//https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        for (auto &i: nums3){
            for(auto &j: nums4){
                mp[i+j]++;
            }
        }
        
        int count=0;
        for (auto &i: nums1){
            for (auto &j: nums2){
                count+=mp[-(i+j)];
            }
        }
        return count;
    }
};