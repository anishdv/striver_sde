//https://practice.geeksforgeeks.org/problems/maximum-sum-path-in-two-arrays5314/1

int maxPathSum(int arr1[], int arr2[], int m, int n) {
	    // code here
	    int sum1=0;
	    int sum2=0;
	    int sum=0;
	    int i=0, j=0;
	    while(i<m && j<n){
	        
	        // let the smaller value giving array reach upto common element and then we will decide which array sum to take
	        if (arr1[i]>arr2[j]){
	            sum2+=arr2[j++];
	        }
	        else if (arr1[i]<arr2[j]){
	            sum1+=arr1[i++];
	        }
	        else{
	            sum1+=arr1[i++];
	            sum2+=arr2[j++];
	            sum+=max(sum1, sum2);
	            sum1=sum2=0;
	        }
	    }
	    
	    
	    while (i<m){
	        sum1+=arr1[i++];
	    }
	    while (j<n){
	        sum2+=arr2[j++];
	    }
	    return sum+max(sum1, sum2);
	}