/*
Problem: Minimum Cost

Approach:
1. Store first element separately.
2. Sort the remaining elements (from index 1).
3. Pick the two smallest from the sorted part.
4. Return sum = first + nums[1] + nums[2].

Time Complexity: O(N log N)
Space Complexity: O(1)
*/

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = nums[0];
        // Sort from index 1 onward
        sort(nums.begin() + 1, nums.end());
        // Add first element + two smallest remaining
        return first + nums[1] + nums[2];
    }
};
