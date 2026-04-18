class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, size_t> counts;
        int n = nums.size();

        for (size_t i = 0; i < n; i++) {
            counts[nums[i]]++;
        }

        for (size_t i = 0; i < n; i++) {
            if (counts[nums[i]] > 1) {return true;}
        }

        return false;

    }
};