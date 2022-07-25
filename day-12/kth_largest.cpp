// this is solution to https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
        
        // solution using min heap
        // tc- o(k+(n-k)logk) sc- o(k)
//         int n=nums.size();
//         int res;
//         priority_queue<int,vector<int>, greater<int>> pq;
        
//         for(int i=0; i<k; i++){
//             pq.push(nums[i]);
//             cout<<pq.top()<<endl;
//         }
//         cout<<pq.top()<<endl;
//         for(int i=k; i<n ; i++){
//             pq.push(nums[i]);
//             cout<<"When"<<nums[i]<<"is pushed"<<pq.top()<<endl;
//             pq.pop();
//         }
        
//         res=pq.top();
//         return res;
        
        
        
        // solution using quick select
        // tc- o(n) sc- o(1)
    int partition(vector<int> &nums, int left, int right){
        cout<<"left="<<left<<"right= "<<right<<endl;
        int l=left+1, r=right;
        int pivot=nums[left];
        while(l<=r){
            if (nums[l]>pivot && nums[r]<pivot){
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            if (nums[l]<=pivot){
                l++;
            }
            if (nums[r]>=pivot){
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int left=0, right=nums.size()-1, kth;
        while (true){
            int ind=partition(nums, left, right);
            cout<<"ind= "<<ind<< endl;
            if (ind==nums.size()-k){
                kth=ind;
                break;
            }
            else if (ind<nums.size()-k){
                left=ind+1;
            }
            else{
                right=ind-1;
            }
        }
        return nums[kth];
    }
    
    
};