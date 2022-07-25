// this is solution to https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        sort(num.begin(),num.end());
        vector<vector<int>> op;
        if (num.size()<3) return op;
        
        //moves for a
        for(int i=0; i<num.size()-2; i++){
            if (i==0 || (num[i]!=num[i-1])){
            int lo=i+1, hi=num.size()-1,sum=0-num[i];
            while(lo<hi){
                if(num[lo]+num[hi]==sum){
                    //insertion in op
                    vector<int> temp;
                    temp.push_back(num[i]);
                    temp.push_back(num[lo]);
                    temp.push_back(num[hi]);
                    op.push_back(temp);
                    // leaving on right lo and hi
                    while(lo<hi && num[lo]==num[lo+1]) lo++;//next is not continuation of present
                    while(lo<hi && num[hi]==num[hi-1]) hi--;
                    
                    lo++; hi--;
                }
                else if(num[lo]+num[hi]<sum) lo++;
                else hi--;
            }
            }
        }
        return op;
    }
};