// this is solution to https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        // set<vector<int>> s;
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        
        // approach is  i and j traverse linearly in nested loop and for rest portion two pointers are used
        for(int i=0;i<n-3;i++){
            for(int j=i+1; j<n-2; j++){
                int a_pointer=j+1;
                int b_pointer=n-1;
                int newtarget=target-nums[i]-nums[j];
                while(a_pointer<b_pointer){
                    sum=nums[a_pointer]+nums[b_pointer];
                    if (sum>newtarget){
                        b_pointer--;
                    }
                    else if(sum<newtarget){
                        a_pointer++;
                    }else if(sum==newtarget){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[a_pointer]);
                        temp.push_back(nums[b_pointer]);
                        res.push_back(temp);
                        // skipping the duplicates of number 3
                        while (a_pointer < b_pointer && temp[2]==nums[a_pointer])a_pointer++;
                        // skipping the duplicates of number 4
                        while (a_pointer < b_pointer && temp[1]==nums[b_pointer])b_pointer--;
                }
            }
                // skipping the duplicates of number 2
                while(j+1<n && nums[j]==nums[j+1]) j++;
                
        }
            // skipping the duplicates of number 1
            while (i+1<n && nums[i]==nums[i+1]) i++;
    }
        
        // for (set<vector<int>>::iterator i = s.begin(); i != s.end(); i++) {
        //    vector<int> element = *i;
        //     res.push_back(element);
        // }
        return res;
    }
};