class LRUCache {
public:
    map<int, int> m; // it will store key value pair
    map<int, list<int> :: iterator> address; // it will store key and its corresponding location in list l
    list<int> l; // this list will keep keys in order of most recently used to least recently used
    int cap, siz;
    
    LRUCache(int capacity) {
        cap=capacity;
        siz=0;
    }
    
    int get(int key) {
        if (m.find(key)!=m.end()){ // key exists so we now need to return its value as well as put it in front of l
            l.erase(address[key]); // we require iterator to call erase function in list and vector
            address.erase(key);// need not to delete from map m because we are just changing position and not updating
            l.push_front(key);
            address[key]=l.begin();
            return m[key];
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (m.find(key)!=m.end()){ // we are going to update value for key and its position in l
            l.erase(address[key]);
            address.erase(key);
            m.erase(key);
            siz--;
            // m[key]=value;
            // l.push_front(key);
            // address[key]=l.begin();
        }
        
        if (siz==cap){ // it cant be hit during the case of updating, we first need to delete the lru key
            int lru=l.back();
            l.pop_back();
            address.erase(lru);
            m.erase(lru);
            siz--;
        }
        
        siz++;
        l.push_front(key);
        m[key]=value;
        address[key]=l.begin();
        
    }
};