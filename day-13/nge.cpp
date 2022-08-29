//https://www.codingninjas.com/codestudio/problems/799354?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int> st;
    vector<int> ans;
    
    for(int i=n-1; i>=0; i--){
        if (st.empty()){
            st.push(arr[i]);
            ans.push_back(-1);
        }
        else{
            
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if (st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());
            
            st.push(arr[i]);
            
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}