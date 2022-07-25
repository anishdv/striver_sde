// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        // that substring may have characters other than those present in t and the answer will be always greater than or equal to size of t
        // revise count occurrences of anagrams also for understanding count use
        
        unordered_map<char, int> mp;
        int m=s.size();
        int n=t.size();
        // firstly i need to make mapping of t
        for (auto& it: t){
            mp[it]++;
        }
        string ans(1e5,' ');
        int count=n;
        int i=0;
        int j=0;
        while(j<m){
                if (count==0){
                    if (j-i+1<ans.size()){
                        ans=s.substr(i,j-i);
                    }
                }
                else if (count<0){ // some of the occurrences of t's letters are extra
                    while(count<0){
                        if (mp.find(s[i])!=mp.end()){
                            mp[s[i]]++;
                            if (mp[s[i]]==0) count++;
                        }
                        i++;
                    }
                }
                else{
                    if (mp.find(s[j])!=mp.end()){
                    mp[s[j]]--;
                    count--;}
                }
            j++;
            cout<<count<<endl;
        }
        return ans;
    }
};