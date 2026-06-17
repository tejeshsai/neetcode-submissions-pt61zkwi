class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        if(stones.empty()) return 0;
        if(stones.size()==1) return stones[0];
        for(int stone:stones){
            pq.push(stone);
        }
        
        while(pq.size()>1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(first == second) continue;
            pq.push(abs(first-second));
        }
        if(pq.size()==0) return 0;
        return pq.top();
    }
};
