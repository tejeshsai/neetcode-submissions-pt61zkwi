class MedianFinder {
public:
    // Left Half Max Heap
    priority_queue<int> leftHeap{};
    // Right Half Min Heap
    priority_queue<
    int, vector<int>, greater<int>> rightHeap{};
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftHeap.push(num);

        if(!rightHeap.empty() && leftHeap.top()>rightHeap.top()){
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }

        if(leftHeap.size()>rightHeap.size()+1){
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }
        if(rightHeap.size()>leftHeap.size()+1){
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
        

    }
    
    double findMedian() {
        if(((int)leftHeap.size()+(int)rightHeap.size())%2 == 0){
            return (double)(leftHeap.top() + rightHeap.top())/2;
        }else{
            if(leftHeap.size()>rightHeap.size()) return leftHeap.top();
            else return rightHeap.top();
        }
    }
};
