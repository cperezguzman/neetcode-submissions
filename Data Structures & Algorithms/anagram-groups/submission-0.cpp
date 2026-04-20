class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> result;

        for (const auto& word : strs) {
            vector<int> count(26, 0);

            for (char ch : word) {
                count[ch - 'a']++;
            }

            string key = to_string(count[0]);
            for (size_t i = 1; i < count.size(); i++) {
                key += ("," + to_string(count[i]));
            }

            result[key].push_back(word);
        }

        vector<vector<string>> anagrams;
        for (const auto& r : result) {
            anagrams.push_back(r.second);
        }

        return anagrams;
    }
};
