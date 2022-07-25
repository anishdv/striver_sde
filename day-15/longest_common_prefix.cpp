// this is solution to https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string op="";
        for(int k=1; k<=strs[0].size(); k++){
            string s=strs[0].substr(0,k);
            for(int j=1; j<n; j++){
                cout<<strs[j].substr(0,k)<<endl;
                if (s==strs[j].substr(0,k)){
                    continue;
                }else{
                    return op;
                }
            }
            op=strs[0].substr(0,k);
        }
        return op;
    }
};