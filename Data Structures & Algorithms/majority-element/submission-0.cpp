class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, size_t> freq;

        for (const int& num : nums) {
            freq[num]++;
        }

        for (const auto& num : freq) {
            if (num.second > floor(nums.size() / 2.0)) {return num.first;}
        }

        return 0;
    }
};