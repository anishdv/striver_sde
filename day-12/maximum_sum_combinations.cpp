// this is solution to https://www.interviewbit.com/problems/maximum-sum-combinations/

class three{
    public:
    int val, idx, jdx;
};
struct cmp{
    
    bool operator()(three a, three b){
        return a.val<b.val;
    }
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n=B.size();
    vector<int> ans;
    
    // Brute Force approach
    // tc-o(n2)
    // we will make min heap
    // int cnt=0;
    // priority_queue<int, vector<int>,greater<int>> pq;
    
    // for (int i=0; i<m; i++){
    //     for (int j=0; j<n ; j++){
    //         if (cnt < C){
    //             pq.push(A[i]+B[j]);
    //             cnt++;
    //         }
    //         else{
    //             pq.push(A[i]+B[j]);
    //             pq.pop();
    //         }
    //     }
    // }
    // cnt=0;
    // while (cnt<C){
    // cnt++;
    // ans.push_back(pq.top());
    // pq.pop();}

    // reverse(ans.begin(), ans.end());



    // optimised approach
    // tc- o(nlogn)
    sort(A.begin(), A.end());
    sort(B.begin(),B.end());

    // making max heap
    priority_queue<three, vector<three>,cmp> pq;
    pq.push({A[n-1] + B[n-1], n-1, n-1});
    set<pair<int,int>> s;
    s.insert({n-1, n-1});

    while(ans.size()!=C){
        three topper=pq.top();
        int vl=topper.val;
        int i=topper.idx;
        int j=topper.jdx;

        pq.pop();
        ans.push_back(vl);

        if (i>0 && s.count({i-1, j})==0){
            pq.push({A[i-1]+B[j], i-1, j});
            s.insert({i-1, j});
        }
        if (j>0 && s.count({i,j-1})==0){
            pq.push({A[i]+B[j-1], i, j-1});
            s.insert({i, j-1});
        }
    }


    return ans;
}
