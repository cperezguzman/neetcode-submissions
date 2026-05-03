class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int> bits(32, 0);

        for (const int& num : nums) {
            for (size_t i = 0; i < 32; i++) {
                bits[i] += (num >> i) & 1;
            }
        }

        int res{};
        uint64_t one = 1;
        size_t n = nums.size();
        for (size_t i = 0; i < 32; i++) {
            if (bits[i] > (n / 2)) {
                if (i == 31) {
                    res -= (one << i);
                }

                else {
                    res |= (1 << i);
                }
            }
        }

        return res;
    }
};