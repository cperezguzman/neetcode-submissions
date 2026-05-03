class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freq;

        for (const string& word : strs) {
            vector<int> count(26, 0);

            for (const char& ch : word) {
                count[ch - 'a']++;
            }

            string key = to_string(count[0]);
            for (size_t i = 1; i < count.size(); i++) {
                key += ("," + to_string(count[i]));
            }

            freq[key].push_back(word);
        }

        vector<vector<string>> anagrams;
        for (const auto& pairs : freq) {
            anagrams.push_back(pairs.second);
        }

        return anagrams;
    }
};
