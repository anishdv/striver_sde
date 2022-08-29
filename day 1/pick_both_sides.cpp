//https://www.interviewbit.com/problems/pick-from-both-sides/

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int curSum=0;
    for(int i=0; i<B; i++){
        curSum+=A[i];
    }
    int maxSum=curSum;
    int inc=n-1, exc=B-1;
    while(inc>=0 && exc>=0){
        curSum+=A[inc--];
        curSum-=A[exc--];
        maxSum=max(maxSum, curSum);
    }
    return maxSum;
}