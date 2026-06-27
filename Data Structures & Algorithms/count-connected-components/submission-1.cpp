class Solution {
public:
int visitCount = 0;
    void dfs(int index, vector<vector<int>>& graph, vector<bool>& visited, int parent){
        if(visited[index]) return;
        visited[index] = true;
        for(int i:graph[index]){
            if(i==parent) continue;
            dfs(i,graph, visited, index);
        }
        
    }


    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(const auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i, graph, visited, -1);
            }
        }
        return count;
    }
};
