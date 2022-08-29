//https://leetcode.com/problems/reverse-bits/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        int sum = 0;
        
        // we have set the mask for the last bit of n
        int mask = 1;
        
        for (int pow = 31; pow >= 0; pow--) {
            // using pow we right shift last bit of n at pow
            sum = sum + ((n & mask) << pow);
            // we left shift the n so its life traversing from right to left
            n >>= 1;
            
        }
        
        return sum;
    }
};