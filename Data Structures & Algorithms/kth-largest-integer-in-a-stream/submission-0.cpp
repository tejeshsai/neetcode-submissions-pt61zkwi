class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        for(int num:nums){
            pq.push(num);
            if(pq.size()>k) pq.pop();
        }
        this->k = k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>k){
            pq.pop();
        } 
        return pq.top();
    }
};
