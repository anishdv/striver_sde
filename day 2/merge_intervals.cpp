// this is solution to https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        vector<vector<int>> op;
        if(intervals.size()==0)return op;
        sort(intervals.begin(),intervals.end());
        vector<int> tempInterval;
        tempInterval=intervals[0];
        for(auto it: intervals){
            if (tempInterval[1]>=it[0]){  // overlapping intervals ...in this case tempInterval[0] is fixed and tempInterval[1] keeps on updating 
                tempInterval[1]=max(tempInterval[1],it[1]);
            }else{
                op.push_back(tempInterval); // no overlapping so now tempInterval will get pushed
                tempInterval=it;
            }
        }
        op.push_back(tempInterval);
        return op;
    }
};