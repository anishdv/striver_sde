// this is solution to https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

bool static cmp(Job a, Job b){
            return a.profit>b.profit;
        }
        
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // answer holding vector ans
        vector<int> ans;
        if (n==0) return ans;
        
        sort(arr, arr+n, cmp);
        
        int cnt=0;
        int prof=0;
        
        // auxiliary vector rec
        int s;
        vector<int> rec(n,-1);
        for (int i=0; i<n ; i++){
            s=arr[i].dead;
            s-=1;
            // cout<<"deadline for this is "<<s<<endl;
            if (rec[s]==-1){
                prof+=arr[i].profit;
                cnt++;
                rec[s]=arr[i].id;
            }
            else{
                while (s>-1){
                    if (rec[s]==-1){
                        prof+=arr[i].profit;
                        cnt++;
                        rec[s]=arr[i].id;
                        break;
                    }
                    else{
                        s--;
                    }
                }
            }
        }
        
        ans.push_back(cnt);
        ans.push_back(prof);
        return ans;
    } 