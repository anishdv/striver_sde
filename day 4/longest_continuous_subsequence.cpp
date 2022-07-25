// this is solution to https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // brute force approach is by sorting
        if (nums.size()==0) return 0;
        if (nums.size()==1) return 1;
        sort(nums.begin(), nums.end());
        int cnt=1;
        int maxCnt=1;
        int i=0;
        while (i+1<nums.size()){
            if (nums[i+1]==nums[i]+1){
                cnt++;
                maxCnt=max(cnt, maxCnt);
            }
            else if (nums[i+1]==nums[i]){
            }
            else cnt=1;
            i++;
        }
        return maxCnt;
        

   // optimised approach using unordered set
	unordered_set<int> s(begin(nums), end(nums));
	int longest = 0;
	for(auto& num : s) { // iterate over set and not vector otw complexity will be huge and you must dereference the iterator in order to retrieve the member of your set.
        if(s.count(num - 1)) continue;
		int j = 1;
		while(s.count(num + j)) j++;
		longest = max(longest, j);
	}
	return longest;


    }
};