// this is solution to  https://leetcode.com/problems/permutation-sequence/


// optimal
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
      vector < int > numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
      }
      numbers.push_back(n);
      string ans = "";
      k = k - 1;
      while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0) {
          break;
        }

        k = k % fact;
        fact = fact / numbers.size();
      }
      return ans;
    }
};

// using next permutation
class Solution {
public:
    
    int numgen(int n){
        int ans=1;
        int temp=1;
        while(temp<n){
            temp++;
            ans=ans*10+temp;
        }
        return ans;
    }
    void nextPerm(string &nums){
int n=nums.size();
        int k=0;
        int l=0;
        for (k=n-2; k>=0; k--){
            if (nums[k]<nums[k+1]){// finding breakpoint in curve.. greater value at greater position is required
                break; 
            }
        }
        
        if (k<0){
            reverse(nums.begin(),nums.end());
        }else{
            for(l=n-1; l>k;l--){ // from right the first element which is greater than breakpoint will be swapped with breakpoint
                if (nums[l]>nums[k]){ 
                    break;
                }
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        } 
        return;
    }
    string getPermutation(int n, int k) {
        string ans;
        int num= numgen(n);
        ans=to_string(num);
        for(int i=0; i<k-1; i++){
            nextPerm(ans);
        }
        cout<<ans<<endl;
        return ans;
    }
};