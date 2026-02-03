/*
Problem: Check if Array is Trionic

Approach:
1. First move forward while elements are strictly increasing.
2. Then move forward while elements are strictly decreasing.
3. Then again move forward while elements are strictly increasing.
4. Ensure each phase exists (non-empty).
5. Finally check that we reached the last index.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return false;

        int i = 0;

        // first strictly increasing
        while(i + 1 < n && nums[i] < nums[i + 1]) i++;
        if(i == 0) return false;   // no first increase
        int p = i;

        // second strictly decreasing
        while(i + 1 < n && nums[i] > nums[i + 1]) i++;
        if(i == p) return false;  // no decrease
        int q = i;

        // third strictly increasing again
        while(i + 1 < n && nums[i] < nums[i + 1]) i++;
        if(i == q) return false;  // no final increase

        // must consume entire array
        return i == n - 1;
    }
};
