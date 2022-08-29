//https://www.codingninjas.com/codestudio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1


// in insertion and deletion both the time complexity is o(logn) and in peeking it is o(1)

void heapify_down(vector<int> &heap, int idx){
    int left=2*idx+1;
    int right=2*idx+2;
    int smallest=idx; // the smallest will come as parent
    
    if (left<heap.size() && heap[left]<heap[idx]){
        smallest=left;
    }
    if (right<heap.size() && heap[right]<heap[smallest]){
        smallest=right;
    }
    
    if (smallest!=idx){
        swap(heap[idx],  heap[smallest] );
        heapify_down(heap, smallest);
    }
    
}

void heapify_up(vector<int> &heap, int idx){
    if (idx !=0 && heap[(idx-1)/2]>heap[idx]){
        swap(heap[idx], heap[(idx-1)/2]);
        heapify_up(heap,(idx-1)/2);
    }
}

void push(vector<int> & heap, int key){
    heap.push_back(key);
    int index= heap.size()-1;
    heapify_up(heap, index);
    return;
}

void pop(vector<int>& heap){
    heap[0]= heap.back();
    heap.pop_back();
    heapify_down(heap,0);
    return;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> heap,ans;
    for(int i=0; i<q.size(); i++){
        if (q[i][0]==1){
            ans.push_back(heap[0]);
            pop(heap);
        }
        else{
            push(heap, q[i][1]);
        }
    }
    return ans;
}
