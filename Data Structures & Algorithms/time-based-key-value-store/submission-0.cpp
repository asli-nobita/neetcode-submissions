class TimeMap { 
    unordered_map<string, vector<pair<string,int>>> kvStore; 
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        kvStore[key].push_back({value, timestamp}); 
    }
    
    string get(string key, int timestamp) {
        auto& vec=kvStore[key]; 
        auto it=upper_bound(vec.begin(),vec.end(),timestamp,[](int t, auto& v) { 
            return t<v.second; 
        });  
        if (it==vec.begin()) return ""; 
        return (*(it-1)).first; 
    }
};
