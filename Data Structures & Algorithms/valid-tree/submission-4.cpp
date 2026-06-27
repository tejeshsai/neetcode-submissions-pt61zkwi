class Solution {
public:
    enum State {
        Unvisited,
        Visiting,
        Visited
    };
    int count = 0;
    bool dfs(int index, vector<vector<int>>& graph, vector<State>& states, int parent){
        if(states[index] == State::Visited) return true;
        if(states[index]==State::Visiting) return false;
        states[index] = State::Visiting;
        for(int i : graph[index]){
            if(i==parent) continue;
            if(!dfs(i, graph, states, index)) return false;
        }
        states[index] = State::Visited;
        count++;
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<vector<int>> graph(n);
        for(const auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<State> states(n, State::Unvisited);
        if(!dfs(0, graph, states, -1)) return false;
        
        return count == n;
    }
};
