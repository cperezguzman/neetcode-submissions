class MyHashSet {
private:
    int set[31251] = {};

    int getMask(int key) {
        return 1 << (key % sizeof(set));
    }
public:
    MyHashSet() {}
    
    void add(int key) {
        set[key / sizeof(key)] |= getMask(key);
    }
    
    void remove(int key) {
        if (contains(key)) {
            set[key / sizeof(key)] ^= getMask(key);
        }
    }
    
    bool contains(int key) {
        return ((set[key / sizeof(key)] & getMask(key)) != 0);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */