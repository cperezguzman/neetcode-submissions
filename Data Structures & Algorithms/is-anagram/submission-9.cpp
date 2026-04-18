class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for (char b : s) {
            map1[b]++;
        }

        for (char a : t) {
            map2[a]++;
        }

        if (map1 == map2) {
            return true;
        }

        return false;
    }
};
