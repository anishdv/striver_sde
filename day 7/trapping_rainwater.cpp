// this is solution to https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        
        // tc- o(n), sc - o(2n)
        vector<int> maxleft;
        vector<int> maxright;
        int maxi=0;
        // prepare maxleft and maxright
        for (int i=0; i< height.size(); i++){
            if (maxi<height[i]){
                maxi=height[i];
            }
            maxleft.push_back(maxi);
        }
        
        maxi=0;
        for (int i=height.size()-1 ; i>=0 ; i--){
            if (maxi<height[i]){
                maxi=height[i];
            }
            maxright.push_back(maxi);
        }
        
        reverse(maxright.begin(),maxright.end());
        
        int balance=0;
        
        for (int i=0; i< height.size(); i++){
            if (min(maxright[i],maxleft[i])>height[i]){
                balance +=( min(maxright[i],maxleft[i])-height[i] );
            }
        }
        return balance;
        
        // most optimal approach
        // tc- o(n) sc- o(1)
        int leftmax=0;
        int rightmax=0;
        int l=0;
        int r=height.size()-1;
        int balance=0;
        
        while (l<=r){
            if (height[l]<=height[r]){
                if (height[l]>leftmax){
                    leftmax=height[l];
                }
                else{
                    balance+=leftmax-height[l];
                }
                l++;
            }
            else{
                if (height[r]>rightmax){
                    rightmax=height[r];
                }
                else{
                    balance+=rightmax-height[r];
                }
                r--;
            }
        }
        return balance;
    }
};