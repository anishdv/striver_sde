class Solution{
    public:
    int solve(vector<int> &A, int B) {
    unordered_map<int,int>visited;
    int cpx = 0;
    long long c=0;
    for(int i=0;i<A.size();i++){
        cpx^=A[i];
        if(cpx==B) c++;
        int h = cpx^B; // from i to k xor is cpx and assuming that B will be result for some sub part
        // h^B= cpx (Assume)--> so h=cpx^B if h is there in hashmap add its frequencies to hashmap
        if(visited.find(h)!=visited.end()){
            c=c+visited[h];
        }
        visited[cpx]++;
    }
    return c;
}
};
