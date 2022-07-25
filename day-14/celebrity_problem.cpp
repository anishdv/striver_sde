//https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        
        // tc- o(n) sc- o(n)
        // vector<int> zeroes(n,0);
        // int i;
        // for (i=0; i<n; i++){
        //     if (M[i]==zeroes){
        //         break;
        //     }
        // }
        // if (i==n) return -1;
        
        // for(int j=0; j<n; j++){
        //     if (i!=j && M[j][i]==0) return -1;
        // }
        // return i;
        
        
        // tc- o(n) sc- o(n)
        stack<int> st;
        for(int i=0; i<n; i++) st.push(i);
        
        while(st.size()>1){
            int a =st.top(); st.pop();
            int b=st.top(); st.pop();
            if (a!=b && M[a][b]=1) st.push(b);
            else st.push(a);
        }
        
        int a=st.top();
        st.pop();
        
        for (int i=0; i<n; i++){
            if (i!=a){
                if (M[a][i]==1 || M[i][a]==0) return -1;
            }
        }
        return a;
    }