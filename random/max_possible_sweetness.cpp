#include <bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

struct cmp{
    bool operator()(const pair<int, int> &candy1, const pair<int,int> &candy2) const{
        return candy1.second== candy2.second ? candy1.first<candy2.first : candy1.second>candy2.second;
    }
};

void solve(){
    int n,d; cin>>n>>d;
    vector<pair<int,int>> candy(n);
    for(int i=0; i<n; i++){
        cin>> candy[i].first;
    }
    for(int i=0; i<n; i++){
        cin>> candy[i].second;
    }
    
    sort(candy.begin(), candy.end());
    int ans=0;
    multiset<pair<int, int>, cmp> mset;
    int l=0;
    for (int r=n-1; r>=0; r--){
        while(l<r && candy[l].first + candy[r].first<=d){
            mset.insert(candy[l++]);
        }
        auto it= mset.find(candy[r]);
        if (l>r && it!=mset.end()){ 
        mset.erase(it);}
        if(mset.empty()){
            auto [cost1, sweet1]= make_pair(0int, 0int);
        }
        else{
            auto[cost1, sweet1]= (*mset.begin());
        }
        auto [cost2, sweet2] = candy[r];

        if(cost1 + cost2 <= d){
            ans = max(ans, sweet1 + sweet2);
        }
    }
    cout<< ans<<endl;
    return;
}

signed main() {
	// your code goes here
	fast;
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	
	return 0;
}
