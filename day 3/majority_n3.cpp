<<<<<<< HEAD
// this is solution to https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // unordered map solution
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        // calculating count for all 
        for (int i=0; i<n ; i++){
            if (mp.find(nums[i])!=mp.end()){
                mp[nums[i]]++;
            }
            else{
                mp[nums[i]]=1;
            }
        }
        
        unordered_map<int,int> :: iterator it;
        for (it=mp.begin(); it!=mp.end(); it++){
            if (it->second>n/3){
                ans.push_back(it->first);
            }
        }
        return ans;
        
    }


    // extended moore voting algorithm
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> ans;
        int n=nums.size();
        int num1=-1;
        int num2=-1;
        int count1=0;
        int count2=0;
        for (int i=0; i< n; i++){
            if (nums[i]==num1){
                count1++;
            }
            else if (nums[i]==num2){
                count2++;
            }
            else if (count1==0){
                num1=nums[i];
                count1++;
            }
            else if (count2==0){
                num2=nums[i];
                count2++;
            }
            else{
                count1--; count2--;
            }
        }
        count1=0;
        count2=0;
        for (int i=0; i<n ;i++){
            if (nums[i]==num1) count1++;
            else if (nums[i]==num2) count2++;
        }
        
        if (count1>n/3) ans.push_back(num1);
        if (count2>n/3) ans.push_back(num2);
        return ans;
    }
=======
// this is solution to https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // unordered map solution
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        // calculating count for all 
        for (int i=0; i<n ; i++){
            if (mp.find(nums[i])!=mp.end()){
                mp[nums[i]]++;
            }
            else{
                mp[nums[i]]=1;
            }
        }
        
        unordered_map<int,int> :: iterator it;
        for (it=mp.begin(); it!=mp.end(); it++){
            if (it->second>n/3){
                ans.push_back(it->first);
            }
        }
        return ans;
        
    }


    // extended moore voting algorithm
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> ans;
        int n=nums.size();
        int num1=-1;
        int num2=-1;
        int count1=0;
        int count2=0;
        for (int i=0; i< n; i++){
            if (nums[i]==num1){
                count1++;
            }
            else if (nums[i]==num2){
                count2++;
            }
            else if (count1==0){
                num1=nums[i];
                count1++;
            }
            else if (count2==0){
                num2=nums[i];
                count2++;
            }
            else{
                count1--; count2--;
            }
        }
        count1=0;
        count2=0;
        for (int i=0; i<n ;i++){
            if (nums[i]==num1) count1++;
            else if (nums[i]==num2) count2++;
        }
        
        if (count1>n/3) ans.push_back(num1);
        if (count2>n/3) ans.push_back(num2);
        return ans;
    }
>>>>>>> 6e6d19c66866201a446620d1a1b7c321f6b69db2
};