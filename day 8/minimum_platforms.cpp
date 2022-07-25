// this is solution to https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

int findPlatform(int arr[], int dep[], int n)

    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep, dep+n);
    	
    	int platformneeded=1, result=1, i=1, j=0;
    	while (i<n && j<n){
    	    if(arr[i]<=dep[j]){
    	        platformneeded++;
    	        i++;
    	    }
    	    else{
    	        platformneeded--;
    	        j++;
    	    }
    	    
    	    result=max(platformneeded, result);
    	}
    	return result;
    }