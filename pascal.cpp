// this is solution to https://leetcode.com/problems/pascals-triangle/


// we need to save some results by ourselves and then we can use the output for further calculations.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> op;
        vector<int> preTemp;
        preTemp.push_back(1);
        op.push_back(preTemp);
        if (numRows==1) return op;
        preTemp.push_back(1);
        op.push_back(preTemp);
        if (numRows==2) return op;
        int level=2;
        while (level<=numRows-1){
            vector<int> temp(level+1,1);
            for(int k=1; k<level;k++){
                temp[k]=op[level-1][k-1]+op[level-1][k];
            }
            op.push_back(temp);
            level++;
        }
        return op;
    }
};

