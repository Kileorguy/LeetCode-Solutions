class KthLargest {
public:
    int kSize;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        kSize = k;
        for(int n: nums){
            pq.push(n);
        }
        if(pq.size() <= 0) return;
        while(pq.size() > k){
            pq.pop();
        }
    }
    
    int add(int val) {
        // cout << pq.size() << endl;
        // cout << pq.top() << " "+to_string(val) << endl;
        if(pq.size() < kSize){
            pq.push(val);
            return pq.top();
        }
        if(pq.top() < val){
            // cout << pq.top() << endl;
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};