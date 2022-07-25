// this is solution to https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int dp[1000+1][1000+1];
    
    int maxLen(string &s1, string &s2, int n, int m){
        if(n==0 || m==0){
            return 0;
        }
        if (dp[n][m]!=-1){
            return dp[n][m];
        }
        
        if(s1[n-1]==s2[m-1]){
            return dp[n][m]=(1+maxLen(s1,s2,n-1,m-1));
        }
        else{
            return dp[n][m]=max(maxLen(s1,s2,n-1,m),maxLen(s1,s2,n,m-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return maxLen(text1,text2,text1.size(),text2.size());
    }
};