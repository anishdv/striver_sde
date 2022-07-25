//https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i=0;
        int j=0;
        long sum=0;
        long maxi=Arr[0];
        
        while(j<N){
            sum+=Arr[j];
            if (j-i+1<=K){
                j++;
            }
            else {
                sum-=Arr[i];
                i++;
                j++;
            }
            maxi=max(sum, maxi);
        }
        
        return maxi;
    }