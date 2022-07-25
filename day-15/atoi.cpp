// this is solution to https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        // escaping leading white spaces
        // then with updated string, signs only be tolerated if at 0th index and if signs are there for further operations i will be updated
        // we will use long for storing ans
        // we will use sign variable for sign
        // we will use isdigit(ch c) 
        if(s.length()==0) return 0;

        int i=0;
         while(i<s.size() && s[i]== ' ') {
             i++;
         }     
        s = s.substr(i); //i ---> last of string
        
        int sign = +1;
        long ans = 0;
        
        if(s[0] == '-') sign = -1;
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
        
        int MAX = INT_MAX, MIN = INT_MIN;
		
        while(i < s.length()) {
            if(s[0] == ' ' || !isdigit(s[i])) break;
            
            ans = ans * 10 + s[i]-'0';
            if(sign == -1 && -1*ans < MIN) return MIN;
            if(sign == 1 && ans > MAX) return MAX;
            
            i++;
        }
        
        return (int)(sign*ans);
    }
};