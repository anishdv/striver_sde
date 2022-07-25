// this is solution to https://practice.geeksforgeeks.org/problems/subset-sums2234/1

void help(vector<int> arr, int n, vector<int> &ans, int total){
        if(n==0){
            ans.push_back(total);
            return;
        }
        int temp=arr[0];
        arr.erase(arr.begin()); // in vector pop_front does not exist so we use erase and then direct it to begin
        help(arr, n-1, ans, total);
        help(arr, n-1, ans, total+temp);
        return;
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        int answer=0;
        vector<int> result;
        help(arr, N, result, answer);
        return result;
    }