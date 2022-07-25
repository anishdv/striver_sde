// this is solution to https://leetcode.com/problems/magnetic-force-between-two-balls/

class Solution {
public:
    bool isPossible(vector<int> &position, int m,int n, int mid){
        int cnt=1;
        int lastEle=position[0];
        for (int i=1; i<n; i++){
            if (position[i]-lastEle >=mid){
                cnt++;
                lastEle=position[i];
            }
        }
        // cout<<"Count is "<<cnt<<endl;
        if (cnt>=m){
            return true;
        }
        else{
            return false;
        }
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(), position.end());
        
        int low=1;
        int high =position[n-1]-position[0];
        while (low<=high){
            int mid= low+((high-low)>>1);
            // cout<<low<<","<<high<<endl;
            if (isPossible(position, m,n, mid)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};