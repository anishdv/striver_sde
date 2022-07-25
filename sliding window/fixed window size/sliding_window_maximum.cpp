class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // 3 approaches are there
        // first is using brute force and it will have time complexity of n*k and sc of 1
        // second will be using priority queue and it will have tc of n*logk and sc of k
        // third will be using deque and it will have tc of n and sc of k
        
        // ------------------------------PRIORITY QUEUE SOLUTION-----------------
        // tc - o(nlogk) sc - o(k)
        
        int n=nums.size();
        vector<int> ans;
        priority_queue<pair<int,int>> pq; // max heap is default heap in c++
        
        // filling for the first window and fixing the size k
        for (int i=0; i<k; i++){
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);
        
        // running loop till the end of nums
        for (int i=k; i<n; i++){
            pq.push({nums[i], i});
            while(!(pq.top().second>i-k)) pq.pop();
            ans.push_back(pq.top().first);
            
        }
        return ans;
        
        //------------------------------DEQUE SOLUTION---------------------------
        // tc - o(n) and sc - o(n)
        int n=nums.size();
        deque<int> dq; // it will have front to back in non-increasing order
        vector<int> ans;
        for (int i=0; i<n; i++){
            
            // if it is going to be out of k and it is in deque
            if (!dq.empty() && dq.front()==i-k) dq.pop_front();
            
            // for finding the right position of the i index to be pushed
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();
            
            // pushing it 
            dq.push_back(i);
            
            // we have made our first window and now max will be pushed in ans
            if (i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};