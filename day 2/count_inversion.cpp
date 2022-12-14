// one method is by using brute approach which will take n^2 time complexity while second method is by using merge sort algo 

int merge(int arr[],int temp[],int left,int mid,int right)
{
    // INSTEAD OF MAKING AN ARRAY EVERY TIME WE HAVE ALLOTED MEMORY ONE TIME AND WE JUST USE THAT
    int inv_count=0;
    int i = left;
    int j = mid;
    int k = left;
    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i); // NEXT COMING ELEMTS OF ARR1 ARE ALSO THEN GREATER THAN JTH
        }
    }
    // --------------------------------------

    // IF ONE IS EXHAUSTED WHILE OTHER IS NOT 
    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];
    // --------------------------------------

    // COPY TEMP BACK IN ARR
    for(i = left ; i <= right ; i++)
        arr[i] = temp[i];
    //---------------------------------------
    
    return inv_count;
}

int merge_Sort(int arr[],int temp[],int left,int right)
{
    int mid,inv_count = 0;
    if(right > left)
    {
        mid = (left + right)/2;

        inv_count += merge_Sort(arr,temp,left,mid);
        inv_count += merge_Sort(arr,temp,mid+1,right);

        inv_count += merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}
