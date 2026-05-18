class TimeMap {
public:
    unordered_map<string,vector<pair<int, string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key)==store.end()){
            return "";
        }
        auto& values = store[key];
        // LAST TRUE OF Valid Region
        int lo = 0;
        int hi = values.size()-1;
        while(lo<hi){
            int mid = lo+(hi-lo+1)/2; // Right Bias
            // Valid Condition
            if(values[mid].first <= timestamp){
                lo = mid;
            }else{
                hi = mid-1;
            }
        }
        if(values[lo].first<=timestamp) return values[lo].second;
        return "";
    }
};
