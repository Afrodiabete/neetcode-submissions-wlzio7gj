class TimeMap {
public:
    map<string, vector<pair<int, string>>> m;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)!= m.end()){
            int head= 0, tail= m[key].size()- 1, pivot;
            while(tail- head> 1){
                pivot= (head+ tail)/ 2;
                if(m[key][pivot].first< timestamp){
                    head= pivot;
                }
                else{
                    tail= pivot;
                }
            }
            if(m[key][tail].first<= timestamp) return m[key][tail].second;
            if(m[key][head].first<= timestamp) return m[key][head].second;
            
        }
        return "";
    }
};
