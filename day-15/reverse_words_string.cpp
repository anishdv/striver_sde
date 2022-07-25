// this is solution to https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        // we will use two pointer approach
    int left = 0;
    int right = s.length()-1;
    
    string temp="";
    string ans="";
    while (left <= right) {
        char ch= s[left];
        if (ch != ' ') {
            temp += ch;
        } else if (ch == ' ') {
            if (temp!=""){
            if (ans!="") ans = temp + " " + ans;
            else ans = temp;}
            temp = "";
        }
        left++;
    }
    
    if (temp!="") {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
    }
    
    return ans;
    }
};