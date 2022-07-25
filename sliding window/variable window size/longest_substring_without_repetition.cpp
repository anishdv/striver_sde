//https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1

int longestSubstrDistinctChars (string s)
{
    // your code here
    int n=s.size();
    unordered_map<char, int> mp;
    int ans=0;
    int i=0;
    int j=0;
    while(j<n){
        if (mp.find(s[j])==mp.end()){
            mp[s[j]]=1;
            ans=max(ans, j-i+1);
        }
        else{
            while(i<=j && mp.find(s[j])!=mp.end()){
                mp[s[i]]--;
                if (mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            mp[s[j]]=1;
        }
        j++;
    }
    return ans;
}