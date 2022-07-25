// this is solution to https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#

class Solution
{
    public:
    bool static comp(Item a, Item b) { // cant remove static keyword from here ...comparators we use for user defined datatypes
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
      sort(arr, arr + n, comp);

      int curWeight = 0;
      double finalvalue = 0.0;
      for (int i = 0; i < n; i++) {

         if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
         } else {
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
            break;
         }
      }

      return finalvalue;

    }
        
};