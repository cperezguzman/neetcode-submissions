class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, size_t> s_freq;
        unordered_map<char, size_t> t_freq;

        for (const char& ch : s) {
            s_freq[ch]++;
        }

        for (const char& ch : t) {
            t_freq[ch]++;
        }

        return s_freq == t_freq;
    }
};
