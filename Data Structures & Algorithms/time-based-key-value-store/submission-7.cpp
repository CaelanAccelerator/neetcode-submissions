class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
       
        auto &values = map[key];
        if(values.size() == 0)return "";
        if (timestamp < values[0].first) return "";
        int l = 0, r = values.size() - 1;
        string res = "";
        while(l <= r){
            int mid = (l + r)/2;
            if(values[mid].first == timestamp)
                return values[mid].second;
            if(values[mid].first > timestamp)
                r = mid - 1;
            else
                l = mid + 1; 
            if(values[mid].first < timestamp){
                res = values[mid].second;
            }
        }
        return res;
    }


    unordered_map<string,vector<pair<int,string>>> map;
};
