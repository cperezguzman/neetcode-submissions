class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    
};

class Trie {
public:
    TrieNode* root;

    Trie() {
	root = new TrieNode();
    }

    void insert(const string& word) {
    	TrieNode* curr = root;

	for (const char& ch : word) {
	    if (curr->children.find(ch) == curr->children.end()) {
	    	curr->children[ch] = new TrieNode();
	    }

	    curr = curr->children[ch];
	}
    }

    size_t lcp(const string& word, size_t prefixLen) {
    	TrieNode* curr = root;

	size_t i = 0;
	for (const char& ch : word) {
	    if (curr->children.find(ch) == curr->children.end()) {
	    	prefixLen = i;
		return prefixLen;
	    }

	    curr = curr->children[ch];
	    i++;
	}

	return prefixLen;

    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& words) {
    	string mini = words[0];

	for (size_t i = 1; i < words.size(); i++) {
	    if (mini.size() > words[i].size()) {
	    	mini = words[i];
	    }
	}

	Trie trie;
	trie.insert(mini);
	size_t prefixLen = mini.size();

	for (size_t i = 1; i < words.size(); i++) {
	    prefixLen = trie.lcp(words[i], prefixLen);
	}

	return mini.substr(0, prefixLen);

    }
};