class MyHashMap {
private:
	struct LinkNode {
		int key{}, val{};
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
        LinkNode* curr = myMap[hash(key)];
		while (curr->next) {
			if (curr->next->key == key) {
				curr->next->val = value;
				return;
			}

			curr = curr->next;
		}

		curr->next = new LinkNode(key, value);
    }
    
    int get(int key) {
        LinkNode* curr = myMap[hash(key)]->next;
		while (curr) {
			if (curr->key == key) {
				return curr->val;
			}

			curr = curr->next; 
		}

		return -1;
    }
    
    void remove(int key) {
        LinkNode* curr = myMap[hash(key)];
		while (curr->next) {
			if (curr->next->key == key) {
				LinkNode* tmp = curr->next;
				curr->next = curr->next->next;
				delete tmp;
				return;
			}

			curr = curr->next;
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