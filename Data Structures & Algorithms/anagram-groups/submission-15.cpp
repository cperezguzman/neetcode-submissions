class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;

	for (const auto& word : strs) {
	    vector<int> count(26, 0);
	    
	    for (const auto& ch : word) {
	    	count[ch - 'a']++;
	    }

	    string key = to_string(count[0]);

	    for (size_t i = 0; i < count.size(); i++) {
	    	key += ("," + to_string(count[i]));
	    }

	    group[key].push_back(word);
	}

	vector<vector<string>> anagrams;

	for (const auto& pair : group) {
	    anagrams.push_back(pair.second);
	}

	return anagrams;
	
    }
};