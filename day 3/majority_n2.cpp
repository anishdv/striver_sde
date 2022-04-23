// this is solution to https://leetcode.com/problems/majority-element/

class Solution {
public:

//  using hashmap 
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int i=0; i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                m[nums[i]]+=1;
            }
            else{
                m[nums[i]]=0;
            }
        }
        unordered_map<int,int>::iterator itr;
        int maxEle=INT_MIN;
        int k=0;
        int keyCorres=-1;
        for(itr=m.begin();itr!=m.end();itr++){
            if (maxEle<itr->second){
                maxEle=itr->second;
                keyCorres=itr->first;
            }
            
        }
        return keyCorres;
        
        
    }

    // moore's voting algorithm
        int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=nums[0];
        
        for(int num:nums){
            if (count==0){
                candidate=num;
            }
            if (num==candidate){
                count++;
            }
            else count--;
        }
        return candidate;
    }

};

