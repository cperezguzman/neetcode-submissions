class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int> bits(32, 0);
		size_t n = nums.size();

		for (const int& num : nums) {
			for (int i = 0; i < 32; i++) {
				bits[i] += ((num >> i) & 1);
			}
		}

		int res {};
		uint64_t one = 1;
		for (size_t i = 0; i < bits.size(); i++) {
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