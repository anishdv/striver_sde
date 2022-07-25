//https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int, int> mp; // it will store sum from 0 to i and i index
        int cursum=0;
        int ans=0;
        for (int i=0; i<N; i++){
            cursum+=A[i];
            
            if (cursum==K){
                ans=max(ans, i+1);
            }
            else{
                if (mp.find(cursum-K)!=mp.end()){
                    int j=mp[cursum-K];
                    ans=max(ans, i-j);
                }
            }
            // cout<<cursum<<" "<<i<<endl;
            if (mp.find(cursum)==mp.end()) mp[cursum]=i; 
            // if the sum is already pushed earlier then no need to push it otw smaller window will be there
        }
        return ans;
    } 