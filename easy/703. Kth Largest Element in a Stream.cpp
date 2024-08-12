class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        // 小的數不管，大的數進來pop最小，queue中只留k個數
        for(int num: nums){
            if(k > min_heap.size())
                min_heap.push(num);
            else if(num > min_heap.top()){
                min_heap.push(num);
                if(min_heap.size() > k)
                    min_heap.pop();
            }
        }
    }
    
    int add(int val) {
        if(k > min_heap.size())
            min_heap.push(val);
        else if(val > min_heap.top()){
            min_heap.push(val);
            min_heap.pop();
        }
        return min_heap.top();
    }
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> min_heap;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
