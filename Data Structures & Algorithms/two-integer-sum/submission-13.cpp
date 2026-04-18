class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;

        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];

            if (indices.count(comp) && indices[comp] != i) {
                return {i, indices[comp]};
            }
        }

        return {};
    }
};
