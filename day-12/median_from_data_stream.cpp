// this is solution to https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    priority_queue<int> pq_pre;
    priority_queue<int,vector<int>,greater<int>> pq_post;
    MedianFinder() {
        // priority_queue<int> pq_pre; // this will act as a max heap
        // priority_queue<int,vector<int>,greater<int>> pq_post; // this will act as a min heap
    }
    
    void addNum(int num) {
        if(pq_pre.size()==0 && pq_post.size()==0){
            pq_pre.push(num);
            return;}
        else if (num>=pq_pre.top()){
            pq_post.push(num);
            if (pq_pre.size()+2==pq_post.size()){
                int temp=pq_post.top();
                pq_post.pop();
                pq_pre.push(temp);
            }
            return;   
        }
        else{
            pq_pre.push(num);
            if (pq_pre.size()==pq_post.size()+2){
                int temp=pq_pre.top();
                pq_pre.pop();
                pq_post.push(temp);
            }
            return;
        }
    }
    
    double findMedian() {
        if (pq_pre.size()>pq_post.size()){
            return (double)pq_pre.top();
        }else if (pq_pre.size()<pq_post.size()){
            return (double)pq_post.top();
        }else{
            double median=(double)(pq_pre.top()+pq_post.top())/2;
            return median;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */