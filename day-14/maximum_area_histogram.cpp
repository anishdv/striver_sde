//https://www.codingninjas.com/codestudio/problems/1058184?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>

vector<int> leftSmaller(vector<int> &heights, int n){
        vector<int> left(n);
        stack<int> st;
        for (int i=0; i<n; i++){
            if (st.empty()){
                st.push(i);
                left[i]=i;
            }
            else {
                while(heights[st.top()]>=heights[i]){
                    st.pop();
                    if(st.empty()){
                        break;
                    }
                }
                if (!st.empty()){
                left[i]=st.top()+1;
                st.push(i);}
                else{
                    st.push(i);
                    left[i]=0;
                }
            }
        }
        return left;
    }
    
    vector<int> rightSmaller(vector<int> &heights, int n){
        vector<int> right(n);
        stack<int> st;
        for (int i=n-1; i>=0; i--){
            if (st.empty()){
                st.push(i);
                right[i]=i;
            }
            else {
                while(heights[st.top()]>=heights[i]){
                    st.pop();
                    if (st.empty()){
                        break;
                    }
                }
                if (!st.empty()){
                right[i]=st.top()-1;
                st.push(i);}
                else{
                    st.push(i);
                    right[i]=n-1;
                }
            }
        }
        return right;
    }
    
    int largestRectangle(vector < int > & heights) {
        
        int n=heights.size();
        vector<int> left= leftSmaller(heights, n);
        vector<int> right= rightSmaller(heights, n);
        int maxi=0;
        for (int i=0; i<n; i++){
            maxi=max(heights[i]*(right[i]-left[i]+1), maxi);
        }
        return maxi;
    }