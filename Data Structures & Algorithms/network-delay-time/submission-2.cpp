class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> table(n+1, INT_MAX);
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto& edge : times){
            graph[edge[0]].push_back({edge[1],edge[2]});
        }

        //table[k] = 0;
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){
            auto [distance, node] = pq.top();
            pq.pop();
            
            if(table[node] < distance){
                continue;
            }
            table[node] = distance;
            for(auto [nNode, nDistance] : graph[node]){
                if(table[nNode]>nDistance+distance){
                    table[nNode] = nDistance + distance;
                    pq.push({table[nNode], nNode});
                }
            } 
        }

        int maximum = -1;
        for(int i=1;i<n+1;i++){
            if(table[i]==INT_MAX) return -1;
            maximum = max(maximum, table[i]);
        }
        return maximum;
    }
};
