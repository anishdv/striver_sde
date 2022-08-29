//https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#define ll long long
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    ll i=0;
    ll j=0;
    queue<ll> negs;
    vector<ll> ans;
    while(j<N){
        // i will make a window of constant size K
        if (j-i+1<K){
            if (A[j]<0) negs.push(j);
            j++;
        }
        
        else{
            //i need to push in ans 
            if (A[j]<0) negs.push(j);
            if (!negs.empty()){
                ans.push_back(A[negs.front()]);
                if (negs.front()==i){
                negs.pop();
                }
            }
            else{
                ans.push_back(0);
            }
            i++;
            j++;
        }
    }
    return ans;                                            
 }

 