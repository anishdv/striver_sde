//https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int>v; // v will store the indices of nge to left
       stack<pair<int, int>> st;
       for (int i=0; i<n; i++){
           if (st.empty()) v.push_back(-1);
           else if (st.size()>0 && st.top().first>price[i]){
               v.push_back(st.top().second);
           }
           else if (st.size()>0 && st.top().first<=price[i]){
               while(st.size()>0 && st.top().first<=price[i]) st.pop();
               if (st.empty()) v.push_back(-1);
               else v.push_back(st.top().second);
           }
           st.push({price[i],i});
       }
       
       for(int i=0; i<n; i++){
           v[i]=i-v[i];
       }
       return v;
    }