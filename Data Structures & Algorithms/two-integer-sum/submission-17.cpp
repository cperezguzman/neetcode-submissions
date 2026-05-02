class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 2) {return {0, 1};}

        unordered_map<int, int> indices;

        for (size_t i = 0; i < nums.size(); i++) {
            indices[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int comp = (target - nums[i]);

            if (indices.count(comp) && (indices[comp] != i)) {
                return {i, indices[comp]};
            }

        }

        return {};


    }
};
