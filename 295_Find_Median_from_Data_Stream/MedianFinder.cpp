class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top() > num) {
            maxHeap.push(num);
        }
        else { // minHeap stores the value that is greater than max value (i.e., maxHeap.top()) in maxHeap
            minHeap.push(num);
        }


        // Balance minHeap & maxHeap, make the difference of their sizes no more than 1
        if(maxHeap.size() > (1 + minHeap.size())) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > (1 + maxHeap.size())) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        else {
            return (maxHeap.size() > minHeap.size())? maxHeap.top() : minHeap.top(); 
        }
    }

private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
};