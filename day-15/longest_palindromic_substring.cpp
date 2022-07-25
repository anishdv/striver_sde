// this is solution to https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
// optimised solution
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, end = 0;
        int l,h;
        for(int i=1;i<n;i++){
            //function for even length palindromic substring....
            l = i-1;
            h = i;
            while(l>=0 && h<=n && s[l] == s[h]){
                if(h-l+1 > end-start+1){
                    start = l;
                    end = h;
                }
                l--;
                h++;
            }
            //for odd numbered palindromic substring....
            l = i-1;
            h = i+1;
            while(l>=0 && h<=n && s[l] == s[h]){
                if(h-l+1 > end-start+1){
                    start = l;
                    end = h;
                }
                l--;
                h++;
            }
        }
        string result = s.substr(start,end-start+1);
        return result;
    }
};
};


class Solution {
public:
    
    string longestPalindrome(string s) {
        // dp solution
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n));
        int start=0,end=0;
        for(int gap=0;gap<n;gap++){
            int i=0,j=gap;// j will move from gap to n-1
            while(j<n){
                if(gap==0){
                    dp[i][j]=true;
                    start=i;end=j;// set them initially for answer
                    
                }
                else if(gap==1){
                    if(s[i]==s[j]) {
                        dp[i][j]=true; // it wont go to check at another place
                        start=i;end=j; // set them for answer
                    }
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j]=true;
                        start=i;
                        end=j;
                        
                    }
                }
                i++;j++;
            }
        }
        return s.substr(start,end-start+1);
    }
    
};