// this is solution to https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

class Solution{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    struct Time{
        int starting;
        int ending;
    };
    
    bool static cmp(Time a, Time b){
        if (a.ending!=b.ending){
            return a.ending<b.ending;
        }
        else{
            return a.starting>=b.starting;
        }
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        // greedy approach can be applied by using the number of meeting hours a meeting takes
        Time calc[n];
        for (int i=0; i<n; i++){
            calc[i].starting=start[i];
            calc[i].ending=end[i];
        }
        
        sort(calc,calc+n, cmp);
        int ans=0;
        int prevEnding=0;
        
        for (auto i=0; i<n ; i++){
            
            if (prevEnding>=calc[i].starting){
                continue;
            }
            else{
                ans++;
                prevEnding=calc[i].ending;
            }
        }
        
        return ans;
        }
};