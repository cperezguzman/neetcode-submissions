class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<size_t> indeces;
        vector<int> new_nums;

        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                indeces.push_back(i);
            }
        }

        for (const size_t i : indeces) {
            new_nums.push_back(nums[i]);
            nums.pop_back();
        }

        for (size_t i = 0; i < indeces.size(); i++) {
            nums[i] = new_nums[i];
        }

        return indeces.size();
    }
};