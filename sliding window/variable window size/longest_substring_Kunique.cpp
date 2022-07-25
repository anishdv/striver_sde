//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

int longestKSubstr(string s, int K) {
    // your code here
    int n=s.size();
    unordered_map<char, int> mp; // character and count 
    int ans=-1;
    int i=0;
    int j=0;
    while(j<n){
        if (mp.find(s[j])==mp.end()){
            if (mp.size()<K){
                mp[s[j]]=1;
            }
            else if (mp.size()==K){
                ans=max(ans, (j-1)-i+1);
                while(mp.size()==K && i<=j){
                    mp[s[i]]--;
                    if (mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                mp[s[j]]=1;
            }
        }
        else {
            mp[s[j]]++;
        }
        j++;
    }
    if (mp.size()==K) ans=max(ans, j-i);
    return ans;
    }