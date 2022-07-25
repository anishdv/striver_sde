// this is solution to https://www.interviewbit.com/problems/matrix-median/


// time complexity -- log2(32)*N*log2(M)--> 32NlogM
// space complexity-- 1

int smallerThanEqualto(vector<int> &row, int key){
    // just return the index of immediate greater element than key
    int low=0;
    int high=row.size()-1;
    while(low<=high){
        int mid=(low+high)>>1;
        if (row[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int low=0;
    int high=1e9;
    int n=A.size();
    int m=A[0].size();
    while(low<=high){
        int mid=(low+high)>>1;
        int cnt=0; // total number of elements that are greater than mid
        for (int i=0; i<n ; i++ ){
            cnt+=smallerThanEqualto(A[i],mid);
        }
        if (cnt<=(n*m)/2) low=mid+1;
        else high=mid-1;
    }
    return low;
}


