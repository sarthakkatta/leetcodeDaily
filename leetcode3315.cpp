/*
 Problem: Min Bitwise Array

 Approach:
 - For each number, try to flip the lowest possible bit such that
   the resulting number is strictly smaller
 - If number is 2, no valid smaller number exists → return -1
 - Traverse bits from LSB to MSB and flip the first unset higher bit

 Time Complexity: O(N * 32)
 Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            // Special case
            if (nums[i] == 2) {
                result.push_back(-1);
                continue;
            }
            bool found = false;
            // Check bits from position 1 to 31
            for (int bit = 1; bit < 32; bit++) {
                // If this bit is already set, skip
                if (nums[i] & (1 << bit))
                    continue;
                // Flip previous bit
                int candidate = nums[i] ^ (1 << (bit - 1));
                result.push_back(candidate);
                found = true;
                break;
            }
            if (!found)
                result.push_back(-1);
        }
        return result;
    }
};
