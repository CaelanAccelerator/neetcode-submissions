class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
        int res = m[key];
        auto pos = ktop[key];    
        ls.erase(pos);
        ls.insert(ls.begin(), key);
        ktop[key] = ls.begin();
        return res;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            auto pos = ktop[key];    
            ls.erase(pos);
            ktop[key] = ls.begin();
        }else{
            size++;
        }
        m[key] = value;
        ls.insert(ls.begin(),key);
        ktop[key] = ls.begin();
        if(m_capacity < size){
            cout<<"pop "<<ls.back()<<endl;
            m.erase(ls.back());
            ktop.erase(ls.back());
            ls.pop_back();
            size--;
        }
    }
private:
    list<int> ls;
    unordered_map<int,int> m;
    unordered_map<int,list<int>::iterator> ktop;
    int m_capacity;
    int size = 0;
};
