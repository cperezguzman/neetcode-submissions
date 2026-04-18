class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, size_t> counts;

        for (size_t i = 0; i < nums.size(); i++) {
            counts[nums[i]]++;
        }

        // for (auto const& [key, val] : counts) {
        //     if (val > 1) {return true;}
        // }

        for (size_t i = 0; i < counts.size(); i++) {
            if (counts[nums[i]] > 1) {return true;}
        }

        return false;

    }
};