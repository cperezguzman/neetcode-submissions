class TrieNode {
public:
	unordered_map<char, TrieNode*> children;
};

class Trie {
public:
	TrieNode* root;

	Trie() {
		root = new TrieNode();
	};

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
		for (size_t i = 0; i < word.size(); i++) {
			if (curr->children.find(word[i]) == curr->children.end()) {
				prefixLen = i;
				return prefixLen;
			}

			curr = curr->children[word[i]];
		}

		return prefixLen;
	}
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string mini = strs[0];
		for (size_t i = 1; i < strs.size(); i++) {
			if (mini.size() > strs[i].size()) {
				mini = strs[i];
			}
		}

		Trie trie;
		trie.insert(mini);
		size_t prefixLen = mini.size();

		for (size_t i = 0; i < strs.size(); i++) {
			prefixLen = trie.lcp(strs[i], prefixLen);
		}

		return mini.substr(0, prefixLen);
    }
};