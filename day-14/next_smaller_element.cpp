//https://www.codingninjas.com/codestudio/problems/1112581?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans (n, 0);
    if (n==0)return ans;
    stack<int> st;
    for (int i=n-1; i>=0; i--){
        if (st.empty()){
            ans[i]=-1;
        }
        else{
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if (st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
        }
        
        st.push(arr[i]);
    }
    return ans;
}