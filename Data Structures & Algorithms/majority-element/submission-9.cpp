class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        size_t count = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
            }
            
            if (candidate == nums[i]) {
                count++;
            }

            else {
                count--;
            }
        }

        return candidate;
    }
};