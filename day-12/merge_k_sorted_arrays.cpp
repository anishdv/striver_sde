// this is solution to https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0

// tc- o(n*k*logk)--> only one element from each row is present in pq
// sc-o(n*k)
#include <bits/stdc++.h>

class three{
    public:
    int val, idx, jdx;
};

struct cmp{
    bool operator()(three a, three b){
        return a.val>b.val;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int> ans;
    int cnt=0;
    int sz=0;
    for (int i=0; i<k ; i++){
        sz+=kArrays[i].size();
    }
    // min heap formed
    priority_queue <three, vector<three>, cmp> pq;
    
    for (int i=0; i<k ; i++){
    pq.push({kArrays[i][0], i, 0});
    }
    
    while(cnt<sz){
        three mini=pq.top();
        pq.pop();
        int miniVal=mini.val;
        ans.push_back(miniVal);
        cnt++;
        int i=mini.idx;
        int j=mini.jdx;
        if (j+1<kArrays[i].size()){
            pq.push({kArrays[i][j+1], i, j+1});
         }
        }
    return ans;
}
