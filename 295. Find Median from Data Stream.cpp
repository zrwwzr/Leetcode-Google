class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top())
            maxHeap.push(num);
        else 
            minHeap.push(num);
        int balance = maxHeap.size() - minHeap.size();
        if(balance > 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(balance < -1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(maxHeap.empty() && minHeap.empty()) return 0;
        if(maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) * 0.5;
        else 
            return minHeap.size() > maxHeap.size() ? minHeap.top() : maxHeap.top();
    }
private:
    priority_queue<int, vector<int>, std::greater<int>> minHeap;
    priority_queue<int> maxHeap;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
