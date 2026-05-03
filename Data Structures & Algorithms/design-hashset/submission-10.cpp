class MyHashSet {
private:
    int mySet[31251] = {};

    int getMask(int key) {
        return 1 << (key % 32);
    }

public:
    MyHashSet() {}
    
    void add(int key) {
        mySet[key / 32] |= getMask(key);
    }
    
    void remove(int key) {
        if (contains(key)) {
            mySet[key / 32] ^= getMask(key);
        }
    }
    
    bool contains(int key) {
        return (mySet[key / 32] & getMask(key)) != 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */