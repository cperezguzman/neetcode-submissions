class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, size_t> freq;

        for (const int& num : nums) {
            freq[num]++;
        }

        for (const auto& item : freq) {
            if (item.second > 1) {
                return true;
            }
        }

        return false;
    }
};