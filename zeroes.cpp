// this is solution to https://leetcode.com/problems/set-matrix-zeroes/submissions/

class Solution {
void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int buff=2147483649;
        //Change all 0 to buff
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==0){
                    mat[i][j]=buff;
                }
            }
        }
        //change all row column to 0 where buff is present except buff
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==buff){
                    int x=i;
                    for(int k=0;k<m;++k){
                        if(mat[x][k]!=buff)
                         mat[x][k]=0;
                    } 
                    x=j;
                    for(int k=0;k<n;++k){
                        if(mat[k][x]!=buff)
                         mat[k][x]=0;
                    }
                }
            }
        }
        //change all buff back to 0.
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==buff){
                    mat[i][j]=0;
                }
            }
        }
    }
};