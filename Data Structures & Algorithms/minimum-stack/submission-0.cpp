class MinStack {
public:
    int minimum;
    stack<pair<int,int>> st;

    MinStack() {
        this->minimum = INT_MAX;

    }
    
    void push(int val) {
        if(st.empty()){
            st.push(pair<int,int>{val, val});
        }else{
            st.push(pair<int, int>{val, min(st.top().second, val)});
        }

    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
