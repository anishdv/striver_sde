// this is solution to https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // we will take counts and put them in min heap of size k
        // when we were putting out the elements the upper one will be the kth 
        
        
        unordered_map<int,int> mp; // it will hold the corresponding count and number
        priority_queue<int, vector<int>, greater<int>> pq; // it will store counts 
        
        for (auto i: nums){
            if (mp.find(i)==mp.end()){
                mp[i]=1;
            }
            else{
                mp[i]++;
            }
        }
        
        unordered_map<int,int>:: iterator it;
        for (it=mp.begin(); it!=mp.end(); it++){
            pq.push(it->second);
            if (pq.size()>k){
                pq.pop();
            }
        }
        
        vector<int> ans;
        // we have found the count value of that now we need to find key of key value pair
        while (k){
        for (auto z:mp){
            if (z.second==pq.top()){
                ans.push_back(z.first);
                pq.pop();
                k--;
            }
        }
        }
        return ans;
    }
};