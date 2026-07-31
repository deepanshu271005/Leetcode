class MedianFinder {
public:

   priority_queue<int>pq1;// max heap
   priority_queue<int,vector<int>,greater<int>>pq2;//min heap
   
   int cnt=0;
    MedianFinder() {
        pq1.push(INT_MIN);
        pq2.push(INT_MAX);
    }
    
    void addNum(int num) {
        if(cnt%2){
            if(pq2.top()>=num){
                pq1.push(num);
            }
            else {
                pq1.push(pq2.top());
                pq2.pop();
                pq2.push(num);
            }

        }
        else {
            if(pq1.top()>=num){
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(num);
            }
            else {
                pq2.push(num);
            }

        }


        cnt++;
    }
    
    double findMedian() {
        if(cnt==0)return NULL;
        if(cnt%2){
           return 1.0*pq2.top();
        }
        
         return (pq1.top()*1.0+pq2.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */