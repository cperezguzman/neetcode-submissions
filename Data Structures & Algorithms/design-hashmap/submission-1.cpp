class MyHashMap {
private:
    struct LinkNode {
        int key {}, val{};
        LinkNode* next;

        LinkNode(int key = -1, int val = -1, LinkNode* next = nullptr) : key(key), val(val), next(next) {};
    };

    vector<LinkNode*> myMap;

    int hash(int key) {
        return (key % myMap.size());
    }

public:
    MyHashMap() {
        myMap.resize(1000);

        for (auto& bucket : myMap) {
            bucket = new LinkNode(0);
        }
    }
    
    void put(int key, int value) {
        LinkNode* cur = myMap[hash(key)];
        while (cur->next) {
            if(cur->next->key == key) {
                cur->next->val = value;
                return;
            }

            cur = cur->next;
        }

        cur->next = new LinkNode(key, value);
    }
    
    int get(int key) {
        LinkNode* cur = myMap[hash(key)]->next;
        while (cur) {
            if (cur->key == key) {
                return cur->val;
            }

            cur = cur->next;
        }

        return -1;
    }
    
    void remove(int key) {
        LinkNode* cur = myMap[hash(key)];
        while (cur->next) {
            if (cur->next->key == key) {
                LinkNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                return;
            }

            cur = cur->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */