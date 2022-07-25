// this is solution to https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=weights[0];
        int high=0;
        int n=weights.size();
        
        for (auto i: weights){
            high+=i;
            low=max(low, i);
        }
        // cout<<low<<","<<high<< endl;
        while (low<=high){
            int daycnt=1;
            int weightfor1=0;
            int mid=(low+high)>>1;
            for (int i=0; i<n ; i++){
                if (weightfor1 + weights[i]<=mid){
                    weightfor1+=weights[i];
                }
                else{
                    daycnt+=1;
                    weightfor1=weights[i];
                }
            }
            if (daycnt<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            cout<<low<<","<<high<<endl;
        }
        return low;
        
    }
};