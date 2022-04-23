// this is solution to https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        bool flag=false;
        
        // base cases
        if (nn==1){
            return x;
        }
        else if (nn==0){
            return 1;
        }
        
        // cant keep it above base cases otw negative-1 will give positive-1 result
        if (nn<0){
            flag=true;
            nn=-1*nn;}
        
        double pow=myPow(x,nn/2);
        if (nn%2==1){
            ans=pow*pow*x;
        }
        else{
            ans=pow*pow;
        }
        
        if (flag==true){
            ans=(double)(1.0)/(double)(ans);
        }
        return ans;
    }
};

