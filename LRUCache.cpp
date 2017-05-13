class LRUCache {
private:
    map<int, int> values; //key, value
    int time_;
    int capacity;
    map<int, int> times; //key, time
    map<int, int> keys; //time, key
    
public:
    LRUCache(int capa) : capacity(capa) {
        time_ = 0;
    }
    
    int get(int key) {
        if(!values.count(key))
            return -1;
        keys.erase(times[key]);
        times[key] = time_;
        keys[time_] = key;
        time_++;
        return values[key];
    }
    
    void set(int key, int value) {
        if(values.count(key))
            keys.erase(times[key]);
        values[key] = value;
        times[key] = time_;
        keys[time_] = key;
        time_++;
        if(values.size() > capacity)
        {
            auto it = keys.begin();
            values.erase(it->second);
            times.erase(it->second);
            keys.erase(it);
        }
    }
};